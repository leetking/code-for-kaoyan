#include "tree.h"
/* 中序遍历看是否有序 */
bool _IsBSTTree(BiTree tree, int *pprev)
{
    if (NULL == tree) return true;
    if (!_IsBSTTree(tree->lchild, pprev))
        return false;
    if (*pprev > tree->data)
        return false;
    *pprev = tree->data;
    if (!_IsBSTTree(tree->rchild, pprev))
        return false;
    /* 上述条件都满足才是二叉排序树 */
    return true;
}
bool IsBSTTree(BiTree tree)
{
    /* INT_MIN 来自 limits.h，最小整数 */
    int prev = INT_MIN;
    return _IsBSTTree(tree, &prev);
}
