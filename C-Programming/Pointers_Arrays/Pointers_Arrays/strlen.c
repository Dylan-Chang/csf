/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strlen.c
 * Author: changdi
 *
 * Created on 2016年6月28日, 下午4:44
 */

#include <stdio.h>
#include <stdlib.h>
int serlen(char *s);
/*
 * 
 */
int main(int argc, char** argv) {
    printf(" %d \n",strlen("hello,word!"));
    printf(" %d \n",strlen("array"));
    printf(" %d \n",strlen("ptr"));
    
    return (EXIT_SUCCESS);
}

int serlen(char *s){
    int n;
    for(n = 0; *s != '\0';s++)
        n++;
    return n;
}

