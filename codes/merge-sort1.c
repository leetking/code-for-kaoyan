void CopyArray(int *arr, int lo, int hi, int *tmpArr)
{
    for (int i = 0; i <= hi-lo; i++)
        arr[lo+i] = tmpArr[i];
}
/**
 * 版本一：递归实现的归并排序
 */
void _MergeSort(int *arr, int lo, int hi, int *tmpArr)
{
    if (lo >= hi) return;
    int mid = lo+(hi-lo)/2;
    int lo1 = lo;
    int lo2 = mid+1;
    _MergeSort(arr, lo1, mid, tmpArr);
    _MergeSort(arr, lo2,  hi, tmpArr);
    /* 合并 */
    int idx = 0;
    while (lo1 <= mid && lo2 <= hi) {
        if (arr[lo1] < arr[lo2]) {
            tmpArr[idx] = arr[lo1];
            lo1 ++;
        } else {
            tmpArr[idx] = arr[lo2];
            lo2 ++;
        }
        idx ++;
    }
    while (lo1 <= mid) {
        tmpArr[idx] = arr[lo1];
        idx ++;
        lo1 ++;
    }
    while (lo2 <= hi) {
        tmpArr[idx] = arr[lo2];
        idx ++;
        lo2 ++;
    }
    /* 把合并后的数组复制回原来数组的区间 [lo, hi] 里 */
    CopyArray(arr, lo, hi, tmpArr);
}
void MergeSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    int *tmpArr = malloc(len * sizeof(int));
    if (NULL == tmpArr) return;
    _MergeSort(arr, 0, len-1, tmpArr);
    free(tmpArr);
}
