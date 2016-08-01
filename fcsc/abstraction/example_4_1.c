/* 
 * File:   example_4_1.c
 * Author: changdi
 * 指针取值
 * Created on 2016年7月27日, 下午3:06
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x,*p;
    x = 10;
    p = &x;
    printf("%d\n",*p);
    int y;
    y = *p;
    printf("%d\n",y);
}

