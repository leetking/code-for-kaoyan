#include "tree.h"
/* 如果是二叉排序树 */
void PrintAncestors(BiTree tree, int x)
{
    while (NULL == tree || x == tree->data) {
        printf("%d ", tree->data);
        if (x < tree->data)
            tree = tree->lchild;
        else
            tree = tree->rchild;
    }
}

/* 一般二叉树 */
bool _PrintAncestors(BiTree tree, int x)
{
    if (NULL == tree) return false;
    if (x == tree->data)
        return true;
    /* 如果左子树或者右子树找到 x，那么当前节点是 x 的祖先，那么输出它 */
    if (_PrintAncestors(tree->lchild, x) || _PrintAncestors(tree->rchild, x)) {
        printf("%d ", tree->data);
        return true;
    }
    return false;
}
void PrintAncestors(BiTree tree, int x)
{
    _PrintAncestors(tree, x);
}
