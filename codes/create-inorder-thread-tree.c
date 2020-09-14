#include "tree.h"
void _CreateInThreadTree(ThreadTree tree, ThreadTree *pprev)
{
    if (NULL == tree) return;

    if (TagChild == tree->ltag)
        _CreateInThreadTree(tree->lchild, pprev);

    if (NULL != *pprev && NULL == (*pprev)->rchild) {
        (*pprev)->rchild = tree;
        (*pprev)->rtag = TagNextNode;
    }
    if (NULL == tree->lchild) {
        tree->lchild = *pprev;
        tree->ltag = TagPrevNode;
    }
    pprev = &tree;

    if (TagChild == tree->rtag)
        _CreateInThreadTree(tree->rchild, pprev);
}
void CreateInThreadTree(ThreadTree tree)
{
    ThreadTree prev = NULL;
    _CreateInThreadTree(tree, &prev);
}
