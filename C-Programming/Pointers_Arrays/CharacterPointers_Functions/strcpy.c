/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   strcpy.c
 * Author: changdi
 *
 * Created on 2016年7月7日, 下午1:30
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {

    return (EXIT_SUCCESS);
}

/*
//数组下标
void strcpy(char *s , char *t){
    int i;
    
    i = 0;
    while((s[i] = t[i]) != '\0'){
        i++;
    }
    
}
 */

/* 指针方式1 */
/*
void strcpy(char *s , char *t){
    
    while((*s = *t) != '\0'){
        s++;
        t++;
    }
}
*/

/* 指针方式2 */
/*
void strcpy(char *s, char *t){
    while((*s++ = *t++) != '\0'){
        ;
    }
}*/

/* 指针方式3 */
void strcpy(char *s , char *t){
    while(*s++ = *t++){
        ;
    }
}




