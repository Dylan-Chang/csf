/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.c
 * Author: changdi
 *
 * Created on 2016年7月11日, 下午1:24
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

typedef struct CELL *LIST;
struct CELL {
    int element;
    struct LIST next; 
};


