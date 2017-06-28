/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   1-4.c
 * Author: changdi
 *
 * Created on 2016年7月28日, 上午10:17
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
/*
    float cel,fah;
    int lower,upper,step;
    
    lower = 0;
    upper = 300;
    step= 20;
    
    cel = lower;
    while(cel <= upper){
       // fah = (5.0/9.0) * (cel -32.0);
        fah = (9.0/5.0) * cel + 32.0;
        printf("%3.0f %6.1f\n",cel,fah);
        cel = cel + step;
    }*/
    
    

  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("C     F\n\n");
  celsius = lower;
  while(celsius <= upper)
  {
    fahr = (9.0/5.0) * celsius + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
  return 0;

}

