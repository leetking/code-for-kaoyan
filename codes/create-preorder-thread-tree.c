#include "tree.h"
void _CreatePreThreadTree(ThreadTree tree, ThreadTree *pprev)
{
    if (NULL == tree) return;

    /* 前驱指向当前节点 */
    if (NULL != *pprev && NULL == (*pprev)->rchild) {
        (*pprev)->rchild = tree;
        (*pprev)->rtag = TagNextNode;
    }
    /* 当前节点指向前驱 */
    if (NULL == tree->lchild) {
        tree->lchild = *pprev;
        tree->ltag = TagPrevNode;
    }
    pprev = &tree;

    if (TagChild == tree->ltag)
        _CreatePreThreadTree(tree->lchild, pprev);
    if (TagChild == tree->rtag)
        _CreatePreThreadTree(tree->rchild, pprev);
}
void CreatePreThreadTree(ThreadTree tree)
{
    ThreadTree prev = NULL;
    _CreatePreThreadTree(tree, &prev);
}
