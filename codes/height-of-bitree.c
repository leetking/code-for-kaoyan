#include "tree.h"
/* 这里给出递归求树的高度，也可以通过非递归的任意遍历求树高 */
int BiTreeHeight(BiTree tree)
{
    if (NULL == tree) return 0;
    int lheight = BiTreeHeight(tree->lchild);
    int rheight = BiTreeHeight(tree->rchild);
    return (lheight>rheight)? (lheight+1): (rheight+1);
}
