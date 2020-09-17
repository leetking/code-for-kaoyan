int Partition(int *arr, int lo, int hi)
{
    int pivot = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[hi] >= pivot)
            hi --;
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= pivot)
            lo ++;
        arr[hi] = arr[lo];
    }
    arr[lo] = pivot;
    return lo;
}
int _FindKthElement(int *arr, int lo, int hi, int k)
{
    int pivot_idx = Partition(arr, lo, hi);
    /* 程序一定是在这里结束递归 */
    if (pivot_idx == k) return arr[pivot_idx];
    if (k > pivot_idx)
        return _FindKthElement(arr, pivot_idx+1, hi, k);
    else
        return _FindKthElement(arr, lo, pivot_idx-1, k);
}
int FindKthElement(int *arr, int len, int k)
{
    if (NULL == arr || len <= 0) return -1;
    if (k <= 0 || k > len) return -1;
    return _FindKthElement(arr, 0, len-1, k-1);
}
