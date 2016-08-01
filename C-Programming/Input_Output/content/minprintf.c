/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   minprintf.c
 * Author: changdi
 *
 * Created on 2016年7月29日, 下午1:55
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
 * 
 */
int main(int argc, char** argv) {

    minprintf("%d %f",1,2.0);
}

void minprintf(char *fmt, ...) {
    va_list ap; /* 依次指向每个无名参数 */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /*将ap指向第一个参数*/
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); //结束时的清理
}