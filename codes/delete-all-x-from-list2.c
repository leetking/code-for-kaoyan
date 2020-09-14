#include "list.h"
void DeleteAllxFromList2(LinkList list, int x)
{
    if (NULL == list || NULL == list->next) return;
    while (NULL != list->next) {
        LinkList curr = list->next;
        if (x == curr->data) {
            free(curr);
            list->next = curr->next;
        } else {
            list = list->next;
        }
    }
}
