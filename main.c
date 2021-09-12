#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define WORDBUFLEN 255
#define PROBUFLEN 1024

char filename[100];

int filter(const struct dirent *p);
void scan(char *s);

int main(int argc, char **argv)
{
    int i, n;
    struct dirent **p;
    n = scandir(argv[1], &p, filter, alphasort);
    for (i = 0; i < n; i++)
    {
        strcpy(filename, argv[1]);
        strcat(filename, p[i]->d_name);
        scan(filename);
    }
    return 0;
}

int filter(const struct dirent *p)
{
    int len = strlen(p->d_name);

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
        if (ch == '#')
        {
            while (ch != '\n')
            {
                ch = fgetc(f);
            }
            continue;
        }
        if (isalpha(ch))
        {
            char cur_prot[PROBUFLEN] = {0};
            int cur_token = 0;
            while (!feof(f))
            {
                if (ch == ';')
                {
                    cur_token = 0;
                    ch = fgetc(f);
                    continue;
                }
                if ((ch == '\n') || (ch == '\r') || (ch == '}'))
                {
                    ch = fgetc(f);
                    continue;
                }
                if (ch == '{')
                {
                    cur_prot[cur_token++] = ';';
                    cur_prot[cur_token] = 0;
                    puts(cur_prot);
                    //skip to right '}'
                    while (ch != '}')
                    {
                        ch = fgetc(f);
                    }
                    ch = fgetc(f);
                    break;
                }
                cur_prot[cur_token] = ch;
                ++cur_token;
                ch = fgetc(f);
            }
        }
    }
}
