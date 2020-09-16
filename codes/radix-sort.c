#include "queue.h"
/* 基数选择为 10 */
#define Radix   10
/**
 * 按照最低位优先 LSD 的基数排序
 */
void RadixSort(int *arr, int len)
{
    if (NULL == arr || len <= 0) return;
    /* 需要 Radix 个队列 */
    LinkQueue queues[Radix];
    int radixLo = 1;
    for (int i = 0; i < Radix; i++)
        InitQueue(&queues[i]);

    bool doned = false;
    while (!doned) {
        /* 把元素按照数位上的数放入对应的队列中 */
        for (int i = 0; i < len; i++) {
            int digit = (arr[i] / radixLo) % Radix;
            EnQueue(&queues[digit], arr[i]);
        }

        /* 收集 */
        int idx = 0;
        int ele;
        for (int i = 0; i < Radix; i++) {
            while (!QueueEmpty(&queues[i])) {
                DeQueue(&queues[i], &ele);
                arr[idx] = ele;
                idx ++;
            }
        }

        radixLo *= Radix;
        /**
         * 如果所有元素都比 radixLo 小，那么说明所有元素的最高位已经排序，
         * 否则元素还没有处理完，还需要继续排序 doned = false
         */
        doned = true;
        for (int i = 0; i < len; i++) {
            if (arr[i] > radixLo)
                doned = false;
        }
    }

    for (int i = 0; i < Radix; i++)
        DestroyQueue(&queues[i]);
}
