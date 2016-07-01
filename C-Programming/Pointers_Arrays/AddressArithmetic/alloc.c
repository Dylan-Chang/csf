/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   handout.c
 * Author: changdi
 *
 * Created on 2016年6月30日, 上午11:03
 */

#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n) { 
        allocp += n;
        return allocp - n; /* old p */ 
    } else
        return n;
}

void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p; 
}



