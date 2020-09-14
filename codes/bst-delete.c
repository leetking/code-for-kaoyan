#include "tree.h"
/**
 * 从树中偷取其最大值的节点，并存储到 store 里
 */
void StealMaxNode(BiTree *ptree, BiTree *store)
{
    while (NULL != (*ptree)->rchild)
        ptree = &(*ptree)->rchild;
    *store = *ptree;
    *ptree = (*store)->lchild;
}
bool BiTreeDelete(BiTree *ptree, int data)
{
    if (NULL == ptree) return false;
    while (NULL != *ptree && data != (*ptree)->data) {
        if (data < (*ptree)->data)
            ptree = &(*ptree)->lchild;
        else
            ptree = &(*ptree)->rchild;
    }
    /* 没有值为 data 的节点 */
    if (NULL == *ptree) return false;

    BiTree lsubtree = (*ptree)->lchild;
    BiTree rsubtree = (*ptree)->rchild;
    free(*ptree);

    /* 左右都有子树的节点的删除 */
    if (NULL != lsubtree && NULL != rsubtree) {
        BiTree maxNode;
        StealMaxNode(&lsubtree, &maxNode);
        *ptree = maxNode;
        (*ptree)->lchild = lsubtree;
        (*ptree)->rchild = rsubtree;
        return true;
    }

    /* 只有左子树的节点的删除 */
    if (NULL != lsubtree) {
        *ptree = lsubtree;
        return true;
    }

    /* 只有右子树的节点的删除 */
    if (NULL != rsubtree) {
        *ptree = rsubtree;
        return true;
    }

    /* 没有左右子树的节点 */
    *ptree = NULL;
    return true;
}
