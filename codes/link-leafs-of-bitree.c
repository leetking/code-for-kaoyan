#include "tree.h"

/* pprevLeaf: pointer on prevLeaf */
void _LinkLeafs(BiTree tree, BiTree *pprevLeaf)
{
    if (NULL == tree) return;
    if (NULL == tree->lchild && NULL == tree->rchild) {
        if (NULL != *pprevLeaf)
            (*pprevLeaf)->rchild = tree;
        tree->lchild = *pprevLeaf;
        pprevLeaf = &tree;
        return;
    }
    _LinkLeafs(tree->lchild, pprevLeaf);
    _LinkLeafs(tree->rchild, pprevLeaf);
}
void LinkLeafs(BiTree tree)
{
    BiTree prevLeaf = NULL;     /* 存储上一片叶子节点地址 */
    _LinkLeafs(tree, &prevLeaf);
}
