#include "tree.h"
int _WPLOfBiTree(BiTree tree, int deepth)
{
    if (NULL == tree) return 0;
    if (NULL == tree->lchild && NULL == tree->rchild)
        return tree->data * (deepth+1);
    return _WPLOfBiTree(tree->lchild, deepth+1)
         + _WPLOfBiTree(tree->rchild, deepth+1);
}
int WPLOfBiTree(BiTree tree)
{
    return _WPLOfBiTree(tree, 0);
}
