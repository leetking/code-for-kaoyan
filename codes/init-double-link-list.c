bool InitDLinkList(DLinkList *dlist)
{
    if (NULL == dlist) return false;
    *dlist = malloc(sizeof(DLinkNode));
    if (NULL == *dlist) return false;
    /* 循环双链表 */
    (*dlist)->prev = (*dlist)->next = *dlist;
    /* 普通双链表 */
    // (*dlist)->prev = (*dlist)->next = NULL;
    return true;
}
