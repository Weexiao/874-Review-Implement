#include <stdio.h>
#include "String.h"

int main() {
    SString T;
    SString S;
    InitString(&S);
    InitString(&T);
    printf("S has T in position %d\n", Index(S, T));
    int next[T.length+1];
    GetNext(T, T.length, next);
    printf("S has T in position %d\n", Index_KMP(S, T, next));
    return 1;
}