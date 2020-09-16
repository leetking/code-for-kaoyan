bool Pop(LinkStack *stack, int *store)
{
    if (NULL == stack || NULL == store) return false;
    if (StackEmpty(stack)) return false;
    LinkList node = stack->top;
    stack->top = node->next;

    *store = node->data;
    free(node);
    return true;
}
