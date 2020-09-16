/**
 * bool 在 C99 以标准类型添加到 C 语言中，来自头文件 <stdbool.h>
 */
bool InitList(SeqList *list, int capacity)
{
    if (NULL == list || capacity <= 0) return false;

    list->data = malloc(capacity * sizeof(int));
    if (NULL == list->data) return false;

    list->length = 0;
    list->capacity = capacity;
    return true;
}
