#include "tree.h"
bool BiTreeInsert(BiTree *ptree, int data)
{
    /* 和向不带头节点单链表中插入数据极其类似 */
    while (NULL != *ptree) {
        if (data == (*ptree)->data)
            return true;
        if (data < (*ptree)->data) {
            ptree = &(*ptree)->lchild;
        } else {
            ptree = &(*ptree)->rchild;
        }
    }

    BiTreeNode *node = malloc(sizeof(BiTreeNode));
    if (NULL == node) return false;
    node->data = data;
    node->lchild = node->rchild = NULL;
    *ptree = node;

    return true;
}
