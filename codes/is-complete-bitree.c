#include "tree.h"
#include "queue.h"
/**
 * 完全二叉树：除了最有一层右边部分外，其余层都是满的
 * 层次遍历时，如果出现空节点，那么其后续元素都应当是空节点
 */
bool IsCompleteBiTree(BiTree tree)
{
#define BiTreeWidthMax  4096
    if (NULL == tree) return true;
    SeqQueue queue;
    InitQueue(&queue, BiTreeWidthMax);
    EnQueue(&queue, tree);

    while (!QueueEmpty(&queue)) {
        BiTree node;
        DeQueue(&queue, &node);
        if (NULL != node) {
            EnQueue(&queue, node->lchild);
            EnQueue(&queue, node->rchild);
        } else {
            while (!QueueEmpty(&queue)) {
                DeQueue(&queue, &node);
                if (NULL != node) {
                    DestroyQueue(&queue);
                    return false;
                }
            }
            DestroyQueue(&queue);
            return true;
        }
    }

    DestroyQueue(&queue);
    return true;
}
