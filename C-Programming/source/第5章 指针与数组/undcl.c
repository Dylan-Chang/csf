#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE  100  


enum {NAME, PARENS, BRACKETS};
           
int tokentype;               /*最后一个记号的类型*/ 
char token[MAXTOKEN];        /*最后一个记号字符串*/
char name[MAXTOKEN];         /*标识符名称*/
char datatype[MAXTOKEN];     /*数据类型为char、int等*/
char out[1000];              /*输出串*/
char buf[BUFSIZE];           /*用于ungetch函数的缓冲区*/
int bufp = 0;                /*buf中下一个空闲位置*/

void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int c);
int gettoken(void); 


/*将声明转换为文字描述符*/
main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF)
    {
        strcpy(out, token);
        while ((type = gettoken()) != '\n')
        {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*')
            {
                sprintf(temp, "(*%s)", out);
                strcpy(out, temp);
            }
            else if (type == NAME)
            {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            }
            else
            {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }

    return 0;
}

/*对一个声明符进行语法分析*/
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';)
        ns++;/*统计字符*的个数*/

    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
        
}

/*分析一个直接声明*/
void dirdcl(void)
{
    int type;

    if (tokentype == '(')  /*形式为(dcl)*/
    {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) /*变量名*/
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}


/*返回下一个标记*/
int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']';)
        {
            ;
        }
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch());)
        {
            *p++ = c;
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
    {
        return tokentype = c;
    }

}
