bool Push(LinkStack *stack, int ele)
{
    if (NULL == stack) return false;
    /* 链表实现的栈的容量为无穷大，所以不存在栈满的情况 */
    LinkNode *node = malloc(sizeof(LinkNode));
    if (NULL == node) return false;
    node->data = ele;

    node->next = stack->top;
    stack->top = node;

    stack->size += 1;
    return true;
}
