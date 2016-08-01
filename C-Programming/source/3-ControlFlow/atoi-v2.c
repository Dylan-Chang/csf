#include <ctype.h>

/* atoi函数:将s转换为整型数*/
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') /*跳过符号*/
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}


