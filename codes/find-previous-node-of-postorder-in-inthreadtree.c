#include "tree.h"
ThreadTree PrevNodeOfPostOrderInThreadTree(ThreadTree tree, ThreadTree node)
{
    if (NULL == tree || NULL == node) return NULL;
    if (TagChild == node->rtag)
        return node->rchild;
    if (TagChild == node->ltag)
        return node->lchild;
    while (NULL != node->lchild) {
        node = node->lchild;
        if (TagChild == node->ltag)
            return node->lchild;
    }
    return NULL;
}
