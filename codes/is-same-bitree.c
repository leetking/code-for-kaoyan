#include "tree.h"
bool IsSameBiTree(BiTree tree1, BiTree tree2)
{
    if (NULL == tree1 && NULL == tree2)
        return true;
    if (NULL != tree1 && NULL != tree2) {
        return IsSameBiTree(tree1->lchild, tree2->rchild)
            && IsSameBiTree(tree1->lchild, tree2->rchild);
    }
    return false;
}
