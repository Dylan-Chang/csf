/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tree-1.c
 * Author: changdi
 *
 * Created on 2016年7月7日, 下午3:58
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    typedef struct NODE *pNODE;
    struct NODE{
        int info;
        pNODE children[BF];
    };
    
    
    
    return (EXIT_SUCCESS);
}

