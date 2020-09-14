#include "tree.h"
int MaxValue(BiTree tree)
{   
    /* 返回 INT_MIN 表示没有最大值，INT_MAX 来自头文件 limits.h */
    if (NULL == tree)
        return INT_MIN;

    while (NULL != tree->rchild)
        tree = tree->rchild;
    return tree->data;
}
bool MinValue(BiTree tree)
{
    if (NULL == tree) return INT_MAX;

    while (NULL != tree->lchild)
        tree = tree->lchild;
    return tree->data;
}
