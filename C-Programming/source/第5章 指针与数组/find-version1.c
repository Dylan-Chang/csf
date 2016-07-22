#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

/*find函数:打印与第一个参数指定的模式匹配的行*/
main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
    {
        printf("Usage: find pattern\n");
    }
    else
    {
        while (getline(line, MAXLINE) > 0)
        {
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
        }
    }

    return found;
}

int getline(char *line, int max)
{
    int c, i;

    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;

}

