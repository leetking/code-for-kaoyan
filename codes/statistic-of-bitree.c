#include "tree.h"
int CountNodes(BiTree tree)
{
    if (NULL == tree) return 0;
    return (1 + CountNodes(tree->lchild) + CountNodes(tree->rchild));
}

int CountLeafs(BiTree tree)
{
    if (NULL == tree) return 0;
    if (NULL == tree->lchild && NULL == tree->rchild)
        return 1;
    return CountLeafs(tree->lchild) + CountLeafs(tree->rchild);
}

int CountForks(BiTree tree)
{
    int cnt = 0;
    if (NULL == tree) return 0;
    if (NULL != tree->lchild && NULL != tree->rchild)
        cnt = 1;
    return (cnt + CountForks(tree->lchild) + CountForks(tree->rchild));
}
