#include <stdio.h>

#define MAXLINE 100  /*允许的输入行的最大长度*/

int max;  /*目前为止发现的最长行的长度*/
char line[MAXLINE];     /*当前的输入行*/
char longest[MAXLINE];  /*用于保存最长的行*/

int getline(void);
void copy(void);

/*打印最长的输入行*/
main()
{
    int len;  /*当前行长度*/
    
    max = 0;
    while ((len = getline()) > 0)
    {
        if (len > max)
        {
            max = len;
            copy();
        }
    }

    if (max > 0)
    { 
        printf("%s", longest);
    }
    
    return 0;
}

/*getline函数: 将一行读入到s中并返回其长度*/
int getline(void)
{
    int c, i;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

/*copy函数: 将from复制到to；这里假定to足够大*/
void copy(void)
{
    int i;
    
    i = 0;
    while ((longest[i] = line[i]) != '\0')
    {
        ++i;
    }
}


