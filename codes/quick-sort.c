int Partition(int *arr, int lo, int hi)
{
    int pivot = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[hi] >= pivot)
            -- hi;
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] <= pivot)
            ++ lo;
        arr[hi] = arr[lo];
    }
    arr[lo] = pivot;
    return lo;
}
void _QuickSort(int *arr, int lo, int hi)
{
    if (lo >= hi) return;
    int pivotIdx = Partition(arr, lo, hi);
    _QuickSort(arr, lo, pivotIdx-1);
    _QuickSort(arr, pivotIdx+1, hi);
}
void QuickSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    _QuickSort(arr, 0, len-1);
}
