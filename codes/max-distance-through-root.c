#include "tree.h"
int MaxDistThroughRoot(BiTree tree)
{
    /**
     * 注意：树的高度等于根节点到最远叶节点距离加一
     * 高度和路劲长度不是完全一回事
     */
     if (NULL == tree) return 0;
     int lheight = BiTreeHeight(tree->lchild);
     int rheight = BiTreeHeight(tree->rchild);
     if (lheight >= 1) lheight -= 1;
     if (rheight >= 1) rheight -= 1;
     return lheight + rheight;
}
