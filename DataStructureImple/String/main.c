#include <stdio.h>
#include "String.h"

int main() {
    SString T;
    SString S;
    InitString(&S);
    InitString(&T);
    printf("Index_Traverse S has T in position %d\n", Index_Traverse(S, T));
    printf("Index_Jump S has T in position %d\n", Index_Jump(S, T));
    int next[T.length+1];
    GetNext(T, T.length, next);
    printf("Index_KMP S has T in position %d\n", Index_KMP(S, T, next));
    return 1;
}