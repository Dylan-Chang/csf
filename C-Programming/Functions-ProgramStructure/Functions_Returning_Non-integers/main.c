/*
 * Returning Non-integers
 */

#include <stdio.h>
#define MAXLINE 100

/* rudimentary calculator */
main() {
    double sum, atof(char []);
    char line[MAXLINE];
    int _getline(char line[], int max);
    sum = 0;
    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
} 