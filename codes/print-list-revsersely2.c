void PrintListReversely(LinkList list)
{   
    if (NULL == list || NULL == list->next) return;
    list = list->next;  /* 去除头节点 */
    /* 存储元素的地址，减少直接复制元素带来的开销 */
    int values[MaxSize];
    int cnt;
    for (cnt = 0; cnt < MaxSize && NULL != list; list = list->next) {
        values[cnt] = list->data;
        cnt ++;
    }
    if (cnt > MaxSize) {
        printf("the amount of data in list is greater than MaxSize(%d).",
                MaxSize);
        return;
    }
    /* 反向输出 */
    while (cnt-- > 0)
        printf("%d ", values[cnt]);
}
