int BinarySearch(int *arr, int len, int x)
{
    if (NULL == arr || len <= 0) return;
    int lo = 0, hi = len-1;
    while (lo <= hi) {
        int mid = lo+(hi-lo)/2;
        if (x == arr[mid])
            return mid;
        if (x < arr[mid])
            hi = mid-1;
        else
            lo = mid+1;
    }
    return -1;
}
