/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   example_1.c
 * Author: changdi
 *
 * Created on 2016年8月1日, 下午1:24
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

/*
 * 
 */
int main(int argc, char** argv) {

    short sx = -12345;
    unsigned short usx = sx;
    
    printf("sx = %d\t",sx);
    show_bytes((byte_pointer) &sx,sizeof(short));
    printf("usx = %u:\t",usx);
    show_bytes((byte_pointer) &usx,sizeof(unsigned short));
}

