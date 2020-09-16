int GetElem(SeqList *list, int idx)
{
    /* 假定元素都是大于 0，返回 -1 表明发生下标越界错误
     * 如果存储的元素是任意整数，那么返回 -1 就不合理，可以修改 GetElem 函数为
     * bool GetElem(SeqList *list, int idx, int *store);
     * 返回 ture，表明正确获取数据，存储到指针 *store 里，
     * 返回 false，表明下标越界
     */
    if (idx < 0 || idx > ListLength(list))
        return -1;
    return list->data[idx];
    /* 对于静态顺序表 */
    //return list.data[idx];
}
