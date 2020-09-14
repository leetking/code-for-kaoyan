#include "tree.h"
bool IsPartOf(BiTree tree, BiTree part)
{
    if (NULL == part)
        return true;
    if (NULL == tree)   /* part 一定不等于 NULL */
        return false;
    if (tree->data != part->data)
        return false;
    return IsPartOf(tree->lchild, part->lchild)
        && IsPartOf(tree->rchild, part->rchild);
}
bool IsPartOfBiTree(BiTree tree, BiTree part)
{
    if (IsPartOf(tree, part))
        return true;
    if (NULL != tree) {
        if (IsPartOf(tree->lchild, part))
            return true;
        if (IsPartOf(tree->rchild, part))
            return true;
    }
    return false;
}
