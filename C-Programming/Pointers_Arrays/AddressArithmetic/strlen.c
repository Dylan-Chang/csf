/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strlen.c
 * Author: changdi
 *
 * Created on 2016年7月7日, 上午11:58
 */

#include <stdio.h>
#include <stdlib.h>
int serlen(char *s);

/*
 * 
 */
int main() {
    printf(" %d \n", strlen("hello,word!"));
    printf(" %d \n", strlen("array"));
    printf(" %d \n", strlen("ptr"));

    return (EXIT_SUCCESS);
}

int strlen(char *s) {
    char *p = s;

    while (*p != '\0') {
        p++;
    }

    return p - s; /* 表示已经检查过的字符数， */
}