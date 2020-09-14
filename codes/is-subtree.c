#include "tree.h"
bool IsEqualBiTree(BiTree tree1, BiTree tree2)
{
    if (NULL == tree1 && NULL == tree2)
        return true;
    if ((NULL != tree1 && NULL != tree2) && (tree1->data == tree2->data)) {
        return IsEqualBiTree(tree1->lchild, tree2->lchild)
            && IsEqualBiTree(tree1->rchild, tree2->rchild);
    }
    return false;
}

bool IsSubTree(BiTree tree, BiTree subtree)
{
    if (IsEqualBiTree(tree, subtree))
        return true;
    if (NULL != tree) {
        if (IsSubTree(tree->lchild, subtree))
            return true;
        if (IsSubTree(tree->rchild, subtree))
            return true;
    }
    return false;
}
