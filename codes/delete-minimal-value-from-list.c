#include "list.h"
void DeleteMinimalValueFromList(LinkList list)
{
    /* INT_MAX 来自头文件 limits.h，典型值为 2^31 (2的31次方) */
    int minValue = INT_MAX; /* 存储最小值 */
    LinkList minPrev;       /* 指向最小值节点的前驱节点 */
    if (NULL == list || NULL == list->next) return;
    for (; NULL != list->next; list = list->next) {
        LinkList curr = list->next;
        if (curr->data < minValue) {
            minValue = curr->data;
            minPrev = list;
        }
    }
    LinkList minNode = minPrev->next;
    minPrev->next = minNode->next;
    free(minNode);
}
