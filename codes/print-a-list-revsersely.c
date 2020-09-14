#include "list.h"
/**
 * 逆向输出有两种策略（注意这里带有头节点）
 * 方法一：函数递归输出，缺点是存在栈溢出的情况
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

/* 方法二：用一个数组暂存数据的地址，然后再逆向输出 */
void PrintListReversely(LinkList list)
{   
    if (NULL == list || NULL == list->next) return;
    list = list->next;  /* 去除头节点 */
    /* 存储元素的地址，减少直接复制元素带来的开销 */
    int *values[MaxSize];
    int cnt;
    for (cnt = 0; cnt < MaxSize && NULL != list; cnt++, list = list->next)
        values[cnt] = &list->data;
    if (cnt > MaxSize) {
        printf("the amount of data in list is greater than MaxSize(%d).", MaxSize);
        return;
    }
    while (cnt-- > 0)
        printf("%d ", *values[cnt]);
}
