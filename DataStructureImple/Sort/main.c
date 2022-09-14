#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

int main() {
    int a[] = {1, 9, 2, 8, 3, 7, 4 ,6, 5};
    int size = sizeof(a) / sizeof(int);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }

//    printf("\nInsertOrder:\n");
//    InsertOrder(a, size);
//    for (int i = 0; i < size; ++i) {
//        printf("%d ", a[i]);
//    }

//    printf("\nHalfFindInsertSort:\n");
//    HalfFindInsertSort(a, size);
//    for (int i = 0; i < size; ++i) {
//        printf("%d ", a[i]);
//    }

//    printf("\nShellSort:\n");
//    ShellSort(a, size);
//    for (int i = 0; i < size; ++i) {
//        printf("%d ", a[i]);
//    }

//    printf("\nBubbleSort:\n");
//    BubbleSort(a, size);
//    for (int i = 0; i < size; ++i) {
//        printf("%d ", a[i]);
//    }

//    printf("\nQuickSort:\n");
//    QuickSort(a,0,size-1);
//    for (int i = 0; i < size; ++i) {
//        printf("%d ", a[i]);
//    }

    printf("\nSelectSort:\n");
    SelectSort(a, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }

    printf("\n");
//
//    int b[] = {0, 1, 2, 1, 0, 0, 1, 1, 2, 0};
//    int b_size = sizeof(b) / sizeof(int);
//    for (int i = 0; i < b_size; ++i) {
//        printf("%d ", b[i]);
//    }
//
//    printf("\nFlag:\n");
//    Flag(b, b_size);
//    for (int i = 0; i < b_size; ++i) {
//        printf("%d ", b[i]);
//    }

    int b[] = {1, 9, 2, 8, 3, 7, 4 ,6, 5};
    int size_b = sizeof(b) / sizeof(int) - 1;
    for (int i = 0; i < size; ++i) {
        printf("%d ", b[i]);
    }

    printf("\nHeapSort:\n");
    HeapSort(b, size_b);
    for (int i = 0; i < size; ++i) {
        printf("%d ", b[i]);
    }
    return 0;
}
