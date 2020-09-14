#include "list.h"
/* 采用插入排序法 */
void SortList(LinkList list)
{
    if (NULL == list || NULL == list->next) return;
    LinkList node = list->next;
    list->next = NULL;
    /* 把余下节点 node，插入到新链表 list */
    LinkList next;
    for (; NULL != node; node = next) {
        next = node->next;
        /* 寻找 */
        LinkList prev = list;
        while (node->data > prev->data && NULL != prev->next)
            prev = prev->next;
        /* 插入 */
        node->next = prev->next;
        prev->next = node;
    }
}
