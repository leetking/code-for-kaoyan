#include "tree.h"
void SwapBiTree(BiTree tree)
{
    if (NULL == tree) return;
    BiTree t = tree->lchild;
    tree->lchild = tree->rchild;
    tree->rchild = t;
    SwapBiTree(tree->lchild);
    SwapBiTree(tree->rchild);
}
