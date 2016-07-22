/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   commutative.c
 * Author: changdi
 *
 * Created on 2016年7月21日, 上午9:51
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    printf("%d",200 * 300 * 400 * 500);
    printf("%d",(500*400) * (300 * 200));
    printf("\n");
    printf("%f",(3.14+1e20) -1e20);
    printf("\n");
    printf("%f", 3.14+(1e20-1e20));
    printf("\n");
    return (EXIT_SUCCESS);
}

