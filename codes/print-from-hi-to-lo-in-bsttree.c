#include "tree.h"
/**
 * 版本一：遍历整棵树，输出满足条件的节点值
 * 类似于中序遍历，只是先右子树后左子树
 */
void PrintFromHiToLoInBSTTree(BiTree tree, int lo, int hi)
{
    if (NULL == tree || lo > hi) return;
    PrintFromHiToLoInBSTTree(tree->rchild, lo, hi); /* 右子树 */
    if (lo <= tree->data && tree->data <= hi)       /* 只输出满足条件的 */
        printf("%d ", tree->data);
    PrintFromHiToLoInBSTTree(tree->lchild, lo, hi); /* 左子树 */
}
/**
 * 版本二：不需要遍历整棵树
 */
void PrintFromHiToLoInBSTTree(BiTree tree, int lo, int hi)
{
    if (NULL == tree || lo > hi) return;

    if (tree->data <= hi)
        PrintFromHiToLoInBSTTree(tree->rchild, lo, hi);

    printf("%d ", tree->data);

    if (tree->data >= lo)
        PrintFromHiToLoInBSTTree(tree->lchild, lo, hi);
}
