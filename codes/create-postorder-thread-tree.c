#include "tree.h"
void _CreatePostThreadTree(ThreadTree tree, ThreadTree *pprev)
{
    if (NULL == tree) return;

    if (TagChild == tree->lchild)
        _CreatePostThreadTree(tree->lchild, pprev);
    if (TagChild == tree->rchild)
        _CreatePostThreadTree(tree->rchild, pprev);

    if (NULL != *pprev && NULL == (*pprev)->rchild) {
        (*pprev)->rchild = tree;
        (*pprev)->rtag = TagNextNode;
    }
    if (NULL == tree->lchild) {
        tree->lchild = *pprev;
        tree->ltag = TagPrevNode;
    }
    pprev = &tree;
}
void CreatePostThreadTree(ThreadTree tree)
{
    ThreadTree prev = NULL;
    _CreatePostThreadTree(tree, &prev);
}
