bool InitQueue(LinkQueue *queue)
{
    if (NULL == queue) return false;
    LinkNode *dummy = malloc(sizeof(LinkNode)); /* 头节点 */
    if (NULL == dummy) return false;
    dummy->next = NULL;

    /**
     * front->[dummy]->NULL
     * rear ----^
     */
    queue->front = queue->rear = dummy;
    queue->size = 0;
    return true;
}
