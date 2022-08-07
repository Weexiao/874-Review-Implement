//
// Created by 九三 on 2022/3/14.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#endif //STRING_STRING_H

// 顺序存储静态字符串
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];    // 字符
    int length;
}SString;

// 顺序存储动态字符串
typedef struct 
{
    char *ch;
    int length;
}HString;

// 链式存储字符串
typedef struct StringNode
{
    //char ch;                    // 每个节点存1个字符，1B
    char ch[4];                 // 每个节点存多个字符
    struct StringNode *next;    // 4B
}StringNode, *String;



int InitString(SString *S){
    int length;
    printf("Please input String length: \n");
    scanf("%d", &length);
    (*S).length = length;
    printf("Please input String\n");
    for (int i = 1; i <= (*S).length; i++) {
        scanf("\n%c",&((*S).ch[i]));
    }
}

int SubString(SString *Sub, SString S, int pos, int len){
    if (pos < 1 || len < 0 || pos+len-1 > S.length)
    {
        return 0;
    }
    for (int i = pos; i < pos+len; i++)
    {
        (*Sub).ch[i]=S.ch[i];
    }
    (*Sub).length=len;
    return 1;
}

int StrCompare(SString S, SString T){
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

int StrLength(SString S){
    return S.length;
}

int Index(SString S, SString T){
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n-m+1)
    {
        SubString(&sub, S, i, m);
        if (StrCompare(sub, T) != 0)
        {
            i++;
        }
        else{
            return i;
        }
    }
    return 0;
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
