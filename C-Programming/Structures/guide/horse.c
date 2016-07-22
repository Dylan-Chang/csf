/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   horse.c
 * Author: changdi
 *
 * Created on 2016年7月7日, 下午2:44
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(void) {

    struct horse {
        char name[20];
    };

    struct horse first_horse;
    printf("Enter the name of the horse:");
    scanf("%s", first_horse.name);
    printf(" is %s ", first_horse.name);
    return 0;
}

