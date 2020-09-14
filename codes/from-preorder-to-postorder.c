#include "tree.h"
/* 这里的顺序存储的满二叉树下标从 0 开始，所以和前面所讲有所差异 */
void postOrder(int *preArr, int currNodeIdx, int len, int *postArr, int *idx)
{
    if (currNodeIdx >= len) return;
    postOrder(preArr, 2*currNodeIdx+1, len, postArr, idx);
    postOrder(preArr, 2*currNodeIdx+2, len, postArr, idx);
    postArr[*idx] = preArr[currNodeIdx];
    (*idx) += 1;
}
void FromPreOrderToPostOrder(int *preArr, int *postArr, int len)
{
    if (len <= 0 || NULL == preArr || NULL == postArr) return;
    int idx = 0;
    postOrder(preArr, 0, len, postArr, &idx);
}
