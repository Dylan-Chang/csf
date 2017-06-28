/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   4-1.c
 * Author: changdi
 *
 * Created on 2016年7月7日, 上午9:58
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

int strrindex(char s[],char t[]){
    int i,j,k,pos;
    
    pos = -1;
    for(i=0;s[i] != '\0';i++){
        for(j=i,k=0;t[k] != '\0' && s[j] == t[k];j++,k++){
            ;
        }
        if(k>0 && t[k] == '\0'){
            pos = 1;
        }
        return pos;
    }
    
}