void SelectSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    for (int i = 0; i < len; i++) {
        int minIdx = i;
        for (int j = i; j < len; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        Swap(&arr[i], &arr[minIdx]);
    }
}
