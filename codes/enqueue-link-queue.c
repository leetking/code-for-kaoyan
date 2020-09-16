bool EnQueue(LinkQueue *queue, int ele)
{
    if (NULL == queue) return false;
    LinkNode *node = malloc(sizeof(LinkNode));
    if (NULL == node) return false;
    node->data = ele;
    node->next = NULL;

    /**
     * front->[dummy]->[node1]->...->[ele]->NULL
     * rear ---------------------------^
     */
    queue->rear->next = node;
    queue->rear = node;

    queue->size += 1;
    return true;
}
