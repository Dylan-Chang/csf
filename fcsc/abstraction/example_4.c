/*
 * C program to count number of input characters
 */

/* 
 * File:   exmple_4.c
 * Author: changdi
 *
 * Created on 2016年7月26日, 上午11:11
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    
    int num;
    num = 0;
    while(getchar() != EOF){
        ++num;
    }
     printf("%d\n",num);
    
}

