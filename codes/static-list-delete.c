bool ListDelete(SeqList *list, int idx, int *ele)
{
    if (idx < 0 || idx > ListLength(list)) return false;
    for (int i = idx; i < ListLength(list)-1; i++) {
        list->data[i] = list->data[i+1];
        /* 对于静态顺序表 */
        // list.data[i] = list.data[i+1];
    }
    list->length = list->length-1;
    return true;
}
