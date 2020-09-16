#include "list.h"
void DeleteMinimalValueFromList(LinkList list)
{
    if (NULL == list || NULL == list->next) return;
    /* INT_MAX 来自头文件 limits.h，典型值为 2^31 (2的31次方) */
    int minValue = INT_MAX; /* 存储最小值 */
    LinkList minPrev;       /* 指向最小值节点的前驱节点 */
    /* 找到最小值的节点的前驱节点 */
    for (; NULL != list->next; list = list->next) {
        LinkList curr = list->next;
        if (curr->data < minValue) {
            minValue = curr->data;
            minPrev = list;
        }
    }
    /* 删除最小值的节点 */
    LinkList minNode = minPrev->next;
    minPrev->next = minNode->next;
    free(minNode);
}
