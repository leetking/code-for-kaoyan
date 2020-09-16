void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void BubbleSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    for (int i = 0; i < len; i++) {
        for (int j = len-1; j-1 >= i; j--) {
            if (arr[j-1] > arr[j]) {
                /* &arr[j-1] 等价于 &(arr[j-1]) 表示求元素 arr[j-1] 的地址 */
                Swap(&arr[j-1], &arr[j]);
            }
        }
    }
}
