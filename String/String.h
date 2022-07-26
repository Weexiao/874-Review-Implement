//
// Created by 九三 on 2022/3/14.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#endif //STRING_STRING_H

# define MAXLEN 255

typedef struct {
    char ch[MAXLEN];    // 字符
    int length;
}SString;

int InitString(SString *S);
int Index_KMP(SString S, SString T, int next[]);
int GetNext(SString T, int length, int next[]);