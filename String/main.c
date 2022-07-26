#include <stdio.h>
#include "String.h"

int InitString(SString *S){
    int length;
    printf("Please input String length");
    scanf("%d\n", &length);
    (*S).length = length;
    printf("Please input String");
    for (int i = 1; i <= (*S).length; ++i) {
        scanf("%c",&(*S).ch[i]);
    }
}

int Index_KMP(SString S, SString T, int next[]){
    int i=1, j=1;
    while (i <= S.length && j<=T.length){
        if (j == 0 || S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        } else{
            j = next[j];
        }
    }
    if (j > T.length)
        return i-T.length;
    else
        return 0;
}

int GetNext(SString T, int length, int next[]){
    next[1] = 0;
    int i=1,j=0;
    while (i < length){
        if (j==0 || T.ch[i]==T.ch[j]) next[++i] = ++j;
        else j=next[j];
    }
}

int main() {
    SString T, S;
    InitString(&S);
    InitString(&T);
    int next[T.length+1];
    GetNext(T, T.length, next);
    int x;
    x = Index_KMP(S, T, next);
    return 0;
}