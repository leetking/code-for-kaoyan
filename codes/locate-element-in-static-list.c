/**
 * 返回 -1 表明没有找到或者出错
 */
int LocateElem(SeqList *list, int ele)
{
    if (NULL == list) return -1;
    for (int i = 0; i < Length(list); i++) {
        if (ele == list->data[i])
            return i;
        /* 对于静态顺序表 */
        //if (ele == list.data[i])
        //    return i;
    }
    /* 没有找到 */
    return -1;
}
