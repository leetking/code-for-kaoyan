void ShellSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    int inc = len;
    /* 最外层循环控制增量 */
    for (int inc = len; inc >= 1; inc /= 2) {
        /* 内层增量为 inc 的普通插入排序 */
        for (int i = inc; i < len; i ++) {
            int tmp = arr[i];
            int j;
            for (j = i; j-inc >= 0 && tmp < arr[j-inc]; j -= inc)
                arr[j] = arr[j-inc];
            arr[j] = tmp;
        }
    }
}
