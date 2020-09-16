bool InitUFSet(UFSet *set, int capacity)
{
    if (NULL == set || capacity <= 0) return false;
    set->nodes = malloc(capacity * sizeof(int));
    if (NULL == set->nodes) return false;
    set->capacity = capacity;
    /* 所有集合初始化为空集 */
    for (int i = 0; i < capacity; i++)
        set->nodes[i] = -1;
    return true;
}
