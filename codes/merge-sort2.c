int min(int x, int y)
{
    return (x<y)? x: y;
}
/**
 * 版本二：非递归实现的归并排序，自底向上
 */
void MergeSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    int *tmpArr = malloc(len * sizeof(int));
    if (NULL == tmpArr) return;
    for (int step = 1; step < len; step *= 2) {
        for (int i = 0; i < len; i += 2*step) {
            int idx = 0;
            int lo1 = i;
            int hi1 = min(i+step, len) -1;
            int lo2 = i+step;
            int hi2 = min(i+2*step, len) -1;
            while (lo1 <= hi1 && lo2 <= hi2) {
                if (arr[lo1] < arr[lo2]) {
                    tmpArr[idx] = arr[lo1];
                    lo1 ++;
                } else {
                    tmpArr[idx] = arr[lo2];
                    lo2 ++;
                }
                idx ++;
            }
            while (lo1 <= hi1) {
                tmpArr[idx] = arr[lo1];
                idx ++;
                lo1 ++;
            }
            while (lo2 <= hi2) {
                tmpArr[idx] = arr[lo1];
                    idx ++;
                    lo2 ++;
            }
            CopyArray(arr, i, hi2, tmpArr);
        }
    }
    free(tmpArr);
}
