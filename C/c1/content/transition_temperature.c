
/* 
 * File:   transition_temperature.c
 * Author: changdi
 *
 * Created on 2016年7月28日, 上午9:56
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 打印华氏温度与摄氏温度对照表 
 */
int main() {
    int fahr, celsius;
    int lower, upper,step;
    
    lower = 0; //下
    upper = 300; //上
    step = 20;
    
    fahr = lower;
    while(fahr <= upper){
        celsius = 5 * (fahr - 32) /9;
        printf("%d\t%d\n",fahr,celsius);
        fahr = fahr + step;
    }
  
}

