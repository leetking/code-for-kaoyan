/**
 * inc: 增量数组，按照从增量从大到小排序，最后一个元素一定为 1
 * incLen: 增量数组的大小
 */
void ShellSortWithInc(int *arr, int len, int *inc, int incLen)
{
    if (NULL == arr || len <= 0 || NULL == inc || incLen <= 0) return;
    /* 最后一个增量必须是 1 */
    if (1 != inc[incLen-1])
        return;
    /* 控制增量 */
    for (int k = 0; k < incLen; k++) {
        for (int i = inc[k]; i < len; i ++) {
            int tmp = arr[i];
            int j;
            for (j = i; j-inc[k] >= 0 && tmp < arr[j-inc[k]]; j -= inc[k])
                arr[j] = arr[j-inc[k]];
            arr[j] = tmp;
        }
    }
}
