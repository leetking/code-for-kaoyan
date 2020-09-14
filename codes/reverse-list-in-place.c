#include "list.h"
void ReverseListInPlace(LinkList list)
{
    if (NULL == list || NULL == list->next) return;
    LinkList node, next;
    /* 把 list 断开成两个链表：list 空链表，node 余下节点 */
    node = list->next;
    list->next = NULL;
    for (; NULL != node; node = next) {
        next = node->next;
        /* 插入头节点之后，普通节点之前 */
        node->next = list->next;
        list->next = node;
    }
}
