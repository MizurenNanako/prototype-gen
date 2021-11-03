#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> //for linux directory searching
#include <dirent.h>    //for linux directory searching
#include <string.h>
#include <ctype.h>

#define WORDBUFLEN 255
#define PROBUFLEN 1024

#define skipline       \
    while (ch != '\n') \
    {                  \
        ch = fgetc(f); \
    }                  \
    continue

#define skiplogicline  \
    while (ch != ';')  \
    {                  \
        ch = fgetc(f); \
    }                  \
    continue

char filename[100];

int filter(const struct dirent *p);
void scan(char *s);

int main(int argc, char **argv)
{
    int i, n;
    //you should change the part of code to search through directories
    //if you are running this under windows
    struct dirent **p;
    n = scandir(argv[1], &p, filter, alphasort);
    for (i = 0; i < n; i++)
    {
        strcpy(filename, argv[1]);
        strcat(filename, p[i]->d_name);
        printf("// %s :\n", filename);
        scan(filename);
    }
    return 0;
}

int filter(const struct dirent *p)
{
    int len = strlen(p->d_name);
    //filt out c source
    if (len > 2 && strcmp(p->d_name + len - 2, ".c") == 0)
        return 1;
    else
        return 0;
}

void scan(char *s)
{
    FILE *f;
    f = fopen(s, "r");
    if (f == NULL)
    {
        printf("cannot open %s\n", s);
        exit(1);
    }

    while (!feof(f))
    {
        char ch = fgetc(f);
        if (ch == '#') //skip preprocessor
        {
            for (int level = 1; level > 0; ch = fgetc(f))
            {
                if (ch == '\n')
                    --level;
                if (ch == '\\')
                    ++level;
            }
        }
        if (ch == '/') //skip comment line and block
        {
            ch = fgetc(f);
            if (ch == '/')
            {
                skipline;
            }
            if (ch == '*')
            {
                while (1)
                {
                    ch = fgetc(f);
                    if (ch == '*')
                    {
                        ch = fgetc(f);
                        if (ch == '/')
                        {
                            break;
                        }
                    }
                }
                continue;
            }
        }
        if (isalpha(ch)) //logical line starts
        {
            char cur_prot[PROBUFLEN] = {0};
            int cur_token = 0;
            while (!feof(f))
            {
                if (ch == ';') //logical line ends
                {
                    break;
                }
                if (ch == '=') //not definition
                {
                    skiplogicline;
                }
                if ((ch == '\n') || (ch == '\r') || (ch == '}')) //jump blank char
                {
                    ch = ' ';
                    cur_prot[cur_token] = ch;
                    ++cur_token;
                    ch = fgetc(f);
                    continue;
                }
                if (ch == '/') //skip comment line
                {
                    ch = fgetc(f);
                    if (ch == '/')
                    {
                        skipline;
                    }
                    if (ch == '*')
                    {
                        while (1)
                        {
                            ch = fgetc(f);
                            if (ch == '*')
                            {
                                ch = fgetc(f);
                                if (ch == '/')
                                {
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                if (ch == '{') //end of prototype
                {
                    if (cur_prot[cur_token - 1] == ' ')
                        --cur_token;
                    cur_prot[cur_token++] = ';';
                    cur_prot[cur_token] = 0; //mark the end
                    if (cur_prot[cur_token - 2] != '=' && strncmp(cur_prot, "struct;", 7) != 0)
                        puts(cur_prot); //output to stdout
                    //skip to right '}'
                    int level = 1;
                    while (level > 0)
                    {
                        ch = fgetc(f);
                        if (ch == '{')
                        {
                            ++level;
                            continue;
                        }
                        if (ch == '}')
                        {
                            --level;
                            continue;
                        }
                        if (ch == EOF) //in case it dont stops
                        {
                            return;
                        }
                    }
                    ch = fgetc(f);
                    break;
                }
                cur_prot[cur_token] = ch; //read more
                ++cur_token;
                ch = fgetc(f);
            }
        }
    }
}
