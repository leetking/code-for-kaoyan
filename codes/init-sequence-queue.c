bool InitQueue(SeqQueue *queue, int capacity)
{
    if (NULL == queue || capacity <= 0) return false;
    queue->data = malloc(capacity * sizeof(int));
    if (NULL == queue->data) return false;
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    //queue->size = 0;
    return true;
}
