bool DeleteDLinkList(DLinkList node)
{
    if (NULL == node) return false;
    /* 获取被删除节点的前驱和后继 */
    DLinkList prev = node->prev;
    DLinkList next = node->next;
    /* 连接前驱和后继元素 */
    prev->next = next;
    next->prev = prev;
    /* 释放被删除的节点 */
    free(node);
    return true;
}
