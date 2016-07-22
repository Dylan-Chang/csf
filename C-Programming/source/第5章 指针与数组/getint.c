#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];  /*用于ungetch函数的缓冲区*/
int bufp = 0;       /*buf中下一个空闲位置*/

/*取一个字符*/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*把字符压回到输入中*/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*将输入中的下一个整型数赋值给*pn*/
int getint(int *pn)
{
    int c, sign;

    /*跳过空白符*/
    while (isspace(c = getch()))
        ;

    /*输入不是一个数字*/
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

