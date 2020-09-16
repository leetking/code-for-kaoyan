int DLinkListLength(DLinkList list)
{
    if (NULL == list) return 0;
    int len = 0;
    /* 让 p = list->next 是为了去掉头节点 */
    for (DLinkList p = list->next; list != p; p = p->next)
        len++;

    /* 普通双链表 */
    //for (DLinkList p = list->next; NULL != p; p = p->next)
    //    len++;

    return len;
}
