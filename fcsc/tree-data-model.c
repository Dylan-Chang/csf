/* 
 * File:   tree-data-model.c
 * Author: changdi
 *
 * Created on 2016年6月27日, 下午2:56
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}


typedef struct NODE *pNODE;
struct NODE{
    int info;
    pNODE children[BF];
};

void preorder(pNODE n){
    pNODE c;
    
}


