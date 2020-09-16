#include "list.h"
/**
 * 注意这里带有头节点
 */
void _PrintListRevsersely(LinkList list)
{
    /* 按照没有头节点单链表来处理 */
    if (NULL == list) return;
    _PrintListRevsersely(list->next);
    printf("%d ", list->data);
}
void PrintListReversely(LinkList list)
{
    /* 对于空链表(带有头节点) 直接返回不进行处理 */
    if (NULL == list || NULL == list->next) return;
    list = list->next;  /* 去除头节点 */
    _PrintListRevsersely(list);
}
