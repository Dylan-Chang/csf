/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   functions.c
 * Author: changdi
 *
 * Created on 2016年7月8日, 上午9:30
 */

#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct rect screen;
struct point middle;
struct point makepoint(int, int);

/*
 * 
 */
int main() {
    struct point temp;
    temp = makepoint(2, 3);

    printf("x:%d y:%d", temp.x, temp.y);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, XMAX);

    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);

    struct point *pp;

    struct point origin, *pp;

    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);


    return (EXIT_SUCCESS);
}

struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

