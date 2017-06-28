

/* 
 * 存储分配程序
 * File:   handout.c
 * Author: changdi
 *
 * Created on 2016年6月30日, 上午11:03
 */

#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 1000

static char allocbuf[ALLOCSIZE];
//初始化指针
static char *allocp = allocbuf; /* 下一个空闲位置 */

/*
 * 
 */
int main() {

    return (EXIT_SUCCESS);
}

/* 返回指向n个字符的指针 */
char *alloc(int n){
    /* 有足够的存储空间 */
    if (allocbuf + ALLOCSIZE - allocp >= n) { 
        allocp += n;
        return allocp - n; /* old p */ 
    } else
        return n;
}

/* 释放p指向的存储区 */
void afree(char *p){
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p; 
}



