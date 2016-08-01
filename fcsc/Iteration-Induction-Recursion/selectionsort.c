#include <stdio.h>

#define MAX 1000
int A[MAX];
void SelectionSort(int A[], int n);

main() {
    int i, n;
    for (n = 0; n < MAX && scanf("%d", &A[n]) != EOF; n++)
        ;
    SelectionSort(A, n);
    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);
}

void SelectionSort(int A[], int n) {
    int i, j, small, tmep;
    for (i = 0; i < n - 1; i++) {
        small = i;
        for (j = i + 1; j < n; j++)
            if (A[j] < A[small])
                small = j;
        tmep = A[small];
        A[small] = A[i];
        A[i] = tmep;
    }
}

