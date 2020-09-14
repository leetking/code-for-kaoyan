#include "list.h"
/**
 * 整体思路和从 list 中删除 x 一样，只是条件不同
 */
void DeleteValuesBetweenLoHiFromList(LinkList list, int lo, int hi)
{
    if (NULL == list || NULL == list->next || lo > hi) return;
    LinkList next;
    while (NULL != list->next) {
        LinkList curr = list->next;
        if (lo <= curr->data && curr->data <= hi) {
            list->next = curr->next;
            free(curr);
        } else {
            list = list->next;
        }
    }
}
