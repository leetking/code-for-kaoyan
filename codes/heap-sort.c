void BuildMaxHeap(int *arr, int len)
{
    for (int k = (len-1)/2; k >= 0; k--)
        AdjustHeap(arr, k, len);
}
/* 调整下标为 k 的元素 */
void AdjustHeap(int *arr, int k, int len)
{
    int top = arr[k];
    int i;
    for (i = 2*i+1; i < len; i = 2*i+1) {
        if (i+1 < len && arr[i] < arr[i+1])
            i++;
        if (top >= arr[i])    /* 余下的已经调整好了 */
            break;
        arr[k] = arr[i];      /* k 是父节点，i 是当前节点 */
        k = i;
    }
    arr[k] = top;
}
/**
 * 元素下标从 0 开始的
 */
void HeapSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    BuildMaxHeap(arr, len);
    for (int i = len-1; i >= 1; i--) {
        Swap(&arr[i], &arr[0]);
        AdjustHeap(arr, 0, i);
    }
}
