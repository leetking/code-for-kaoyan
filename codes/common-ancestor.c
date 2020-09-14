#include "tree.h"
/**
 * 按照从节点 node 往上到根 tree 的顺序，
 * 储所有祖先到 ancestorArr 数组内（包含 node 节点），
 * 并且存储祖先数量到 arrLen 指针指向的整数里
 * 返回 true，表明获取成功
 *      false, 表明 node 不是树 tree 的节点
 * 思路和 PrintAncestors 一样
 */
bool GetAllAncestors(BiTree tree, BiTree node, BiTree *ancestorArr, int *arrLen)
{
    if (NULL == tree) return false;
    if (tree == node
            || GetAllAncestors(tree->lchild, node, ancestorArr, arrLen)
            || GetAllAncestors(tree->rchild, node, ancestorArr, arrLen)) {
        ancestorArr[*arrLen] = node;
        (*arrLen) += 1;
    }
    return false;
}
BiTree CommonAncestor(BiTree tree, BiTree p, BiTree q)
{
#define BiTreeHeightMax 4096
    if (NULL == tree || NULL == p || NULL == q) return NULL;

    int pLen = 0, qLen = 0;
    BiTree pAncestors[BiTreeHeightMax], qAncestors[BiTreeHeightMax];

    /* 如果没有获取成功，p 就不是 tree 的节点 */
    if (!GetAllAncestors(tree, p, pAncestors, &pLen))
        return NULL;
    if (!GetAllAncestors(tree, q, qAncestors, &qLen))
        return NULL;

    while (pAncestors[pLen] == qAncestors[qLen]) {
        pLen -= 1;
        qLen -= 1;
    }
    /**
     * 循环结束，此时 pAncestors[pLen] != qAncestors[qLen]
     * 确有， pAncestors[pLen+1] == qAncestors[qLen+1]
     */

    return pAncestors[pLen+1];
}
