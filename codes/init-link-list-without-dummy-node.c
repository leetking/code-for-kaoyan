/**
 * 不带头结点的单链表初始化
 */
 bool InitList(LinkList *list)
 {
    if (NULL == list) return false;
    *list = NULL;
    return true;
 }
 /**
  * 对于不带头节点的单链表也可以不使用函数来初始化链表，而是按照如下方式
  * 因为无头节点，直接以空指针当作空链表
  */
 LinkList list = NULL;
