#include "tree.h"
int HeightOfValueInBSTTree(BiTree tree, int value)
{
    if (NULL == tree) return 0;

    int height = 1;
    while (NULL != tree) {
        if (value == tree->data)
            return height;
        if (value < tree->data)
            tree = tree->lchild;
        else
            tree = tree->rchild;
        height += 1;
    }

    return -1;  /* 在树 tree 中没有找到值为 value 的节点 */
}
