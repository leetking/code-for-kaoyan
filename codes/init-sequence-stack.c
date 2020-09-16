bool InitStack(SeqStack *stack, int capacity)
{
    if (NULL == stack || capacity <= 0) return false;
    stack->top = -1;
    stack->capacity = capacity;
    stack->data = malloc(capacity * sizeof(int));
    if (NULL == stack->data) return false;
    return true;
}
