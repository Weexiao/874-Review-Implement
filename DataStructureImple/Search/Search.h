typedef struct 
{
    int *elem;          // 动态数组基址
    int TableLen;       // 表长度
}SSTable;

int InitSSTabe(SSTable *ST, int size){
    ST->elem = (int *)malloc(sizeof(int)*(size+1));
    ST->TableLen = size;
}

// 顺序查找
int Search_Seq(SSTable ST, int key){
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i]!=key; i++);
    // 查找成功则返回，否则返回-1
    return i==ST.TableLen?-1:i;
}

// 顺序查找有哨兵版
int Search_Seq_Guard(SSTable ST, int key){
    ST.elem[0]=key;                 // 哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i]!=key; i--);
    return i==0?-1:i;                       // 查找成功为i，失败为0
}

// 折半查找，基于有序表
int Binary_Search(SSTable ST, int key){
    int low=1, high=ST.TableLen, mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if(ST.elem[mid] == key) return mid;
        else if (ST.elem[mid] < key) low = mid + 1;
        else high = mid -1;
    }
    return -1;
}