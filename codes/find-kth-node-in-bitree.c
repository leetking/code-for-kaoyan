#include "tree.h"
BiTree FindKthNodeInBiTree(BiTree tree, int k)
{
    if (NULL == tree || k <= 0) return NULL;
    int lsubtreeNodes = 0;
    if (NULL != tree->lchild)
        lsubtreeNodes = tree->nodes;
    if (lsubtreeNodes + 1 == k)
        return tree;
    if (k <= lsubtreeNodes)
        return FindKthNodeInBiTree(tree->lchild, k);
    else
        return FindKthNodeInBiTree(tree->rchild, k - lsubtreeNodes - 1);
}
