/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recursion.c
 * Author: changdi
 *
 * Created on 2016年7月29日, 上午11:35
 */

#include <stdio.h>
#include <stdlib.h>

int printd(int);
/*
 * 
 */
int main() {
    printd(123);
    
}

int printd(int n){
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if(n / 10){
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

