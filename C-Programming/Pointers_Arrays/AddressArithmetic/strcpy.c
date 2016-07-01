/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strpty.c
 * Author: changdi
 *
 * Created on 2016年6月30日, 上午11:19
 */

#include <stdio.h>
#include <stdlib.h>
void _strcpy(char *s, char *t);

/*
 * 
 */
void main() {

    char *s = "c";
    char *t = "asd";
    _strcpy(s, t);
    //  return (EXIT_SUCCESS);
}

void _strcpy(char *s, char *t) {
    int i;
    i = 0;

    while ((s[i] = t[i]) != '\0') {

        i++;
    }

    printf("%s \n", s);
   // printf("%s \n", t);


}

