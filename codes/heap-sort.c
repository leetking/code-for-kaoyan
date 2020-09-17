void BuildMaxHeap(int *arr, int len)
{
    for (int k = (len-1)/2; k >= 0; k--)
        AdjustHeap(arr, k, len);
}
/* 调整下标为 k 的元素 */
void AdjustHeap(int *arr, int len, int k)
{
    int t = arr[k];
    int i = k;
    while (true) {
        i = 2*i + 1;
        if (i >= len)       /* 调整到叶子节点了 */
            break;
        if (i+1 < len && arr[i] < arr[i+1])
            i++;
        if (t >= arr[i])    /* 余下的已经调整好了 */
            break;
        arr[k] = arr[i];    /* k 是父节点，i 是当前节点 */
        k = i;
    }
    arr[k] = t;
}
/**
 * 元素下标从 0 开始的
 */
void HeapSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    BuildMaxHeap(arr, len);
    for (int i = len-1; i > 0; i--) {
        Swap(&arr[i], &arr[0]);
        AdjustHeap(arr, 0, i-1);
    }
}
