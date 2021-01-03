bool ListInsert(SeqList *list, int idx, int ele)
{
    if (idx < 0 || idx > ListLength(list)) return false;
    /* 存储空间已满 */
    if (ListFull(list)) return false;
    for (int i = Length(list); i > idx; i--) {
        list->data[i] = list->data[i-1];
        /* 对于静态顺序表 */
        // list.data[i] = list.data[i-1];
    }
    list->data[idx] = ele;
    list->length += 1;
    return true;
}
