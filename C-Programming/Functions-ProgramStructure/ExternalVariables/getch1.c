#include <stdio.h>
#define BUFFSIZE 1000
char buf[BUFFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(void){
    int c;
    if(buf >= BUFFSIZE){
        printf("ungetch : too many");
    }else{
        buf[bufp++] = c;
    }
}


