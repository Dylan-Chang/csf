/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tran_temp_2.c
 * Author: changdi
 *
 * Created on 2016年7月28日, 上午10:06
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * folat 浮点数版
 */
int main(int argc, char** argv) {

    float fahr, celsius;
    int lower, upper, step;
    
    lower =0;
    upper = 300;
    step = 20; //忘加这个变量会造成死循环
    fahr = lower;
    
    while(fahr <= upper){
        celsius = (5.0 /9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr,celsius);
        fahr = fahr + step;
    }
}

