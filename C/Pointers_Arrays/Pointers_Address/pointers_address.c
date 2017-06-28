/* 
 * File:   pointers_address.c
 * Author: changdi
 *
 * Created on 2016年6月28日, 下午3:16
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    int x = 1, y = 2, z[10];
    int *ip;
    ip = &x;
  //  *ip = 100;
    printf("%d \n", ip);
   // printf("%d \n", x);
    y = *ip;
    printf("%d \n", y);
    *ip = 0;
    printf("%d \n", x);
    ip = &z[0];
    printf("%d \n", ip);

}

