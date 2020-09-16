bool DeleteDLinkList(DLinkList node)
{
    if (NULL == node) return false;
    /* 获取被删除节点的前驱和后继 */
    DLinkList prev = node->prev;
    DLinkList next = node->next;
    /**
     * 连接前驱和后继元素
     * 注意：如果 node 是第一个元素，那么 prev 是空指针 NULL
     *       同理，如果 node 是最后一个元素，那么 next 是 NULL
     */
    if (NULL != prev)
        prev->next = next;
    if (NULL != next)
        next->prev = prev;
    /* 释放被删除的节点 */
    free(node);
    return true;
}
