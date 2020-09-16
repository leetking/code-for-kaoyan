/**
 * 无论有没有头节点，释放方法都一样
 */
 void DestroyList(LinkList list)
 {
    LinkList next;
    for (; NULL != list; list = next) {
        next = list->next;
        free(list);
    }
}
