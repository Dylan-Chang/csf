/* 
 * File:   main.c
 * Author: changdi
 *
 * Created on 2016年6月28日, 下午3:53
 */

#include <stdio.h>
#include <stdlib.h>
int swap(int a, int b);
/*
 * 
 */
int main() {
    swap(10,99);
    
}

void swap(int *px, int *py){
    int temp;
    
    temp = *px;
    printf("%d \n", temp);
    *px = *py;
    printf("%d \n", px);
    *py = temp;
    printf("%d \n", py);
    
    
}