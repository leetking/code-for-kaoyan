void InsertSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    for (int i = 1; i < len; i ++) {
        /* 把 arr[i] 存储到 tmp，留出 arr[i] 空位 */
        int tmp = arr[i];
        int j;
        /* 把比 tmp 大的元素往后移，给 tmp 留出空位 */
        for (j = i; j-1 >= 0 && tmp < arr[j-1]; j -= 1) {
            arr[j] = arr[j-1];
        /* 插入 tmp 元素到空位 */
        arr[j] = tmp;
    }
}
