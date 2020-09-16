#include "tree.h"
void PrintFromHiToLoInBSTTree(BiTree tree, int lo, int hi)
{
    if (NULL == tree || lo > hi) return;

    if (tree->data <= hi)
        PrintFromHiToLoInBSTTree(tree->rchild, lo, hi);

    printf("%d ", tree->data);

    if (tree->data >= lo)
        PrintFromHiToLoInBSTTree(tree->lchild, lo, hi);
}
