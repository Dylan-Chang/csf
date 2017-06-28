
/* 
 * File:   tolower.c
 * Author: changdi
 *
 * Created on 2016年7月29日, 下午1:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * 字符大写转小写
 */
int main() {
    
    int c;
   
    while((c = getchar()) != EOF){
        putchar(tolower(c));
    }
    
}

