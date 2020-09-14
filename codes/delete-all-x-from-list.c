#include "list.h"
void DeleteAllxFromList(LinkList *plist, int x)
{
    /**
     * 使用二级指针后代码虽然简洁，但是理解有点复杂，尝试画图理解吧
     * 二级指针的思想就是：把节点想象成汤圆，指针就是用来插汤圆的牙签，
     * 二级指针就是握住牙签的手
     * 空链表：就是一根光溜溜的牙签
     */
    if (NULL == plist) return;

    while (*plist != NULL) {
        /**
         * plist 是手，*plist 就是手上的牙签，(*plist)->next 下一个汤圆的牙签
         * 让“手”握住下一个“汤圆"的“牙签”
         */
        LinkList *pnext = &(*plist)->next;  /* -> 优先级高于 & */
        if (x == (*plist)->data) {
            free(*plist);
            *plist = *pnext;
        } else {
            plist = pnext;
        }

    }
}
