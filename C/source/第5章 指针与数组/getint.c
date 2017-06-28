#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];  /*����ungetch�����Ļ�����*/
int bufp = 0;       /*buf����һ������λ��*/

/*ȡһ���ַ�*/
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/*���ַ�ѹ�ص�������*/
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*�������е���һ����������ֵ��*pn*/
int getint(int *pn)
{
    int c, sign;

    /*�����հ׷�*/
    while (isspace(c = getch()))
        ;

    /*���벻��һ������*/
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

