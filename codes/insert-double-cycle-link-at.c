/**
 * 插入元素 ele 到插入点 at 之后
 */
bool InsertDLinkListAt(DLinkList at, int ele)
{
    if (NULL == at) return false;
    /* 分配好新插入的节点 node */
    DLinkNode *node = malloc(sizeof(DLinkNode));
    if (NULL == node) return false;
    node->data = ele;

    DLinkList next = at->next;
    /**
     * 插入后节点构成顺序 at, node, next
     * 所以上述语句 next = at->next，是为了获取 node 的后继节点
     * 然后直接连接起来即可
     */
    node->next = next;
    node->prev = at;
    next->prev = node;
    at->next = node;
    return true;
}
