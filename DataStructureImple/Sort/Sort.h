// 插入排序
void InsertSort(int A[], int n){
    int i, j, temp;
    for(i = 1; i < n; i++){
        if(A[i] < A[i-1]){
            temp = A[i];
            for(j = i-1; j >= 0 && A[j] > temp; j--)
                A[j+1] = A[j];
            A[j+1]=temp;
        }
    }
}

// 折半查找插入排序(无哨兵)
void HalfFindInsertSort(int A[], int n){
    int i, j, low, mid, high, temp;
    for (i = 1; i < n; i++)
    {
        temp = A[i];
        low = 0, high = i - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if(A[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        for(j = i-1; j >= low; j--)
            A[j+1] = A[j];
        A[low] = temp;
    }
}

// 折半查找插入排序(哨兵)
void HalfFindInsertSort_Guard(int A[], int n){
    int i, j, low, mid, high;
    for (i = 2; i <= n; i++)
    {
        A[0] = A[i];
        low = 1; high = i-1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (A[mid] > A[0]) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i-1; j >= low; j--)
            A[j+1] = A[j];
        A[low] = A[0];
    }
}

// 希尔排序
void ShellSort(int A[], int n){
    int d, i, j;
    for(d = n/2; d >= 1; d = d/2){
        for (i = d; i < n; i++)
        {
            if(A[i] < A[i-d])
            {
                int temp = A[i];
                for (j = i-d; j>=0 && A[j]>temp; j-=d)
                    A[j+d] = A[j];
                A[j+d] = temp;
            }
        }
    }
}

// 交换两数的值
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void BubbleSort(int A[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = n-1; j > i; j--)
        {
            if (A[j-1] > A[j])
            {
                swap(&(A[j-1]), &(A[j]));
                flag = 1;
            }
        }
        if (!flag)
            return;
    }
}

// 快速排序划分
int Partition(int A[], int low, int high){
    int pivot = A[low];             // 确定基轴
    while (low < high){
        if (low < high && A[high] >= pivot) --high;
        A[low] = A[high];
        if (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

// 快速排序
void QuickSort(int A[], int low, int high){
    if (low < high){
        int pivotpos = Partition(A, low, high);   // 划分
        QuickSort(A, low, pivotpos-1);
        QuickSort(A, pivotpos+1, high);
    }
}

// 荷兰国旗
void Flag(int A[], int n){
    int i=0, j=0, k=n-1;
    while (j<=k){
        if (A[j] == 0) swap(&(A[j++]), &(A[i++]));
        if (A[j] == 1) j++;
        if (A[j] == 2) swap(&(A[j]), &(A[k--]));
    }
}

// 简单选择排序
void SelectSort(int A[], int n){
    int min = 0;
    for (int i = 0; i < n-1; ++i) {
        min = i;
        for (int j = i+1; j < n; ++j) {
            if (A[j] < A[min]) min = j;
        }
        if (min != i) swap(&(A[min]), &(A[i]));
    }
}

// 大顶堆堆排序
//void HeadAdjust(int A[], int k, int n){
//    A[0] = A[k];
//    for (int i = 2*k; i <= n; i*=2) {
//        if (i < n && A[i]<A[i+1]) i++;
//        if (A[0] > A[i]) break;
//        else{
//            A[k] = A[i];
//            k=i;
//        }
//    }
//    A[k] = A[0];
//}
//void BuildMaxHeap(int A[], int n){
//    for (int i = n/2; i > 0; i--) {
//        HeadAdjust(A, i, n);
//    }
//}
//void HeapSort(int A[], int n){
//    BuildMaxHeap(A, n);
//    for (int i = n; i > 1; i--) {
//        swap(&(A[i]), &(A[1]));
//        HeadAdjust(A, 1, i-1);
//    }
//}

// 小顶堆排序
void HeadAdjust(int A[], int k, int n){
    A[0] = A[k];
    for (int i = 2*k; i <= n; i*=2) {
        if (i < n && A[i]>A[i+1]) i++;
        if (A[0] < A[i]) break;
        else{
            A[k] = A[i];
            k=i;
        }
    }
    A[k] = A[0];
}
void BuildMaxHeap(int A[], int n){
    for (int i = n/2; i > 0; i--) {
        HeadAdjust(A, i, n);
    }
}
void HeapSort(int A[], int n){
    BuildMaxHeap(A, n);
    for (int i = n; i > 1; i--) {
        swap(&(A[i]), &(A[1]));
        HeadAdjust(A, 1, i-1);
    }
}