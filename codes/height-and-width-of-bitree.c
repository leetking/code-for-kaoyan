#include "tree.h"
#include "queue.h"
int max(int x, int y)
{
    return (x>y)? x: y;
}
bool BiTreeWidthAndHeight(BiTree tree, int *width, int *height)
{
#define TreeWidthMax    10240
    if (NULL == height || NULL == width) return false;
    *height = 0;
    *width = 0;
    if (NULL == tree) return true;

    SeqQueue queue;
    BiTree lastEnQueue;

    InitQueue(&queue, TreeWidthMax);
    EnQueue(&queue, &tree);
    lastEnQueue = tree;         /* 每一层的最后一个入队列的元素 */

    while (!QueueEmpty(&queue)) {
        int width2 = 0;
        BiTree thisLayerLastEnQueue = NULL;

        /* 处理一层 */
        while (true) {
            BiTree node;
            DeQueue(&queue, &node);
            width2 ++;
            if (NULL != node->lchild) {
                EnQueue(&queue, &node->lchild);
                thisLayerLastEnQueue = node->lchild;
            }
            if (NULL != node->rchild) {
                EnQueue(&queue, &node->rchild);
                thisLayerLastEnQueue = node->rchild;
            }
            if (lastEnQueue == node)
                break;
        }

        lastEnQueue = thisLayerLastEnQueue;
        *height += 1;
        *width = max(*width, width2);
    }


    DestroyQueue(&queue);
    return true;
}
