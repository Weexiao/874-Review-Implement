#include<stdio.h>
#include<stdlib.h>
#include"Search.h"

int main(){
    // 初始化SSTable
    SSTable ST;
    InitSSTabe(&ST, 5);
    for (int i = 1; i <= ST.TableLen; i++)
        ST.elem[i] = i;

    printf("Search_Seq Is there a 1?: %d\n", Search_Seq(ST, 1));
    printf("Search_Seq_Guard Is there a 5?: %d\n", Search_Seq_Guard(ST, 5));
    printf("Binary_Search Is there a 4?: %d\n", Binary_Search(ST, 4));
}