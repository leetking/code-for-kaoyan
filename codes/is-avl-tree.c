#include "tree.h"
int abs(int x)
{
    return (x<0)? (-x): x;
}
int max(int x, int y)
{
    return (x>y)? x: y;
}
/**
 * pprev: 指向存储当前节点的前驱节点的值
 * pheight: 指向存储子树高度的变量
 * 这个函数实际上就是通过中序遍历即判断了是否是二叉排序树，
 * 同时求出左右子树高度并判断高度之差是否小于等于 1
 * 也就是组合了判断是否是二叉排序树的函数和求树高的函数
 */
bool _IsAVLTree(BiTree tree, int *pprev, int *pheight)
{
    if (NULL == tree) {
        *pheight = 0;
        return true;
    }

    int lheight, rheight;
    if (!_IsAVLTree(tree->lchild, pprev, &lheight))
        return false;
    if (*pprev > tree->data)
        return false;
    *pprev = tree->data;
    if (!_IsAVLTree(tree->rchild, pprev, &rheight))
        return false;

    *pheight = 1 + max(lheight, rheight);

    return (abs(lheight - rheight) <= 1);
}
bool IsAVLTree(BiTree tree)
{
    int prev = INT_MIN;
    int height;
    return _IsAVLTree(tree, &prev, &height);
}
