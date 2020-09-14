#include "tree.h"
#include "stack.h"
#include "queue.h"
void ReLevelOrder(BiTree tree)
{
    /* 层次遍历加逆序输出 */
#define BiTreeNodesMax  10240
    if (NULL == tree) return;
    SeqStack stack;
    SeqQueue queue;
    InitQueue(&queue, BiTreeNodesMax);
    InitStack(&stack, BiTreeNodesMax);

    EnQueue(&queue, &tree);
    while (!QueueEmpty(&tree)) {
        BiTree node;
        DeQueue(&queue, &node);
        Push(&stack, node->data);
        if (NULL != node->lchild)
            EnQueue(&queue, &node->lchild);
        if (NULL != node->rchild)
            EnQueue(&queue, &node->rchild);
    }

    while (!StackEmpty(&stack)) {
        int data;
        Pop(&stack, &data);
        printf("%d ", data);
    }
    printf("\n");

    DestroyStack(&stack);
}
