bool DeQueue(LinkQueue *queue, int *store)
{
    if (NULL == queue || NULL == store) return false;
    if (QueueEmpty(queue)) return false;

    /**
     * front->[dummy]->[node2]->...->[noden]->NULL
     * rear ---------------------------^
     * node ->[node1]
     */
    LinkList node = queue->front->next;
    queue->front->next = node->next;
    /* 如果是最后一个元素 */
    if (node == queue->rear)
        queue->rear = queue->front;
    queue->size -= 1;

    *store = node->data;
    free(node);
    return true;
}
