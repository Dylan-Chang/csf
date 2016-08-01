/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>

main(int argc,int *argv[]){
    FILE *fp;
    void filecory(FILE *,FILE *);
    
    if(argc == 1){
        filecory(stdin,stdout);
    }else{
        while(--argv > 0){
            if(fp = fopen(*++argv,'r') == NULL){
                printf("cat:%s\n",*fp);
                return 1;
            }else{
                filecory(fp,stdout);
                fclose(fp);
            }
        }
    }
    
    
}

void filecory(FILE *ifp,FILE *ofp){
    int c;
    while((c = getc(ifp)) != EOF){
        putc(c,ofp);
    }
    
}

