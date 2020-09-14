#ifndef QUEUE_H__
#define QUEUE_H__

typedef struct SeqQueue {
    int *data;
    int capacity;
    int front, rear;
    /* 通过 size 记录存储元素的个数，进而作为另一种判断队列是否为空的方法 */
    // int size;
} SeqQueue;

bool InitQueue(SeqQueue *queue, int capacity);
void DestroyQueue(SeqQueue *queue);
bool QueueEmpty(SeqQueue *queue);
bool QueueFull(SeqQueue *queue);
int QueueSize(SeqQueue *queue);
bool EnQueue(SeqQueue *queue, int ele);
bool DeQueue(SeqQueue *queue, int *store);
bool GetHead(SeqQueue *queue, int *store);


#endif /* QUEUE_H__ */
