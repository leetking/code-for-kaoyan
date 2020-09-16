/**
 * 带头节点的初始化
 * LinkList 实际上是指向 LinkNode 类型的指针
 * 所以 list 指针也就是一个指向 LinkNode 类型的 “二级指针”，
 * 也就是所谓的指向指针的指针， list 指向 LinkList 类型的指针
 */
bool InitList(LinkList *list)
{
    if (NULL == list) return false;
    *list = malloc(sizeof(LinkNode));
    (*list)->next = NULL;
    return true;
}
