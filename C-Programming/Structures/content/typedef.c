/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   typedef.c
 * Author: changdi
 *
 * Created on 2016年7月8日, 下午4:29
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Length;
Length len, maxlen;
Length *lengths[];

typedef char *String;
String p, lineptr[MAXLINES],alloc(int);
int strmap(String, String);

p = (String) malloc(100);

typedef struct tnode *Treeptr;
typedef struct tnode{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};



/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}
