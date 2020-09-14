#include "tree.h"
/**
 * 重构过程也是先序的过程，所以即从 preArr 中不断取元素构建即可，
 * 同时根据 inArr 数组来确定某个节点有没有左右子树，
 * 进而决定 preArr 余下的的节点在这个节点左子树还是右子树
 */
BiTree _ReBuildBiTree(int *preArr, int preIdx, int len,
        int *inArr, int inIdx, int inEnd)
{
    if (preIdx >= len || inIdx >= inEnd)
        return NULL;

    int rootData = preArr[preIdx];
    BiTree root = malloc(sizeof(BiTreeNode));
    if (NULL == root) return NULL;
    root->data = rootData;

    /* 在中序数组 inArr 中找到 rootData，然后划分成两部分 */
    int i;
    for (i = inIdx; i < inEnd; i++) {
        if (rootData == inArr[i])
            break;
    }
    /* 数据有误，在中序数组中没能找到先序数组中的元素 */
    if (i == inEnd) {
        printf("Invalid input data in preArr or inArr.\n");
        return NULL;
    }

    int lpreIdx = preIdx+1;
    int rpreIdx = preIdx+1 + (i-inIdx); 
    root->lchild = _ReBuildBiTree(preArr, lpreIdx, len, inArr, inIdx, i);
    root->rchild = _ReBuildBiTree(preArr, rpreIdx, len, inArr, i+1, inEnd);

    return root;
}
BiTree ReBuildBiTree(int *preArr, int *inArr, int len)
{
    if (len <= 0 || NULL == preArr || NULL == inArr) return NULL;
    return _ReBuildBiTree(preArr, 0, len, inArr, 0, len);
}
