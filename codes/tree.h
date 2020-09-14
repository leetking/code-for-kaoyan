#ifndef TREE_H__
#define TREE_H__

#include "common.h"

typedef struct BiTreeNode {
    int data;
    int nodes;      /* 树一章最后一道例题需要 */
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode;
typedef BiTreeNode *BiTree;

typedef struct ThreadTreeNode {
    int data;
    struct ThreadTreeNode *lchild, *rchild;
#define TagChild    0
#define TagPrevNode 1
#define TagNextNode 1
    int ltag, rtag;
} ThreadTreeNode;
/**
 * ltag 为 TagChild    (0) 时，lchild 指向左孩子节点
 * ltag 为 TagPrevNode (1) 时，lchild 指向前驱节点
 * rtag 为 TagChild    (0) 时，rchild 指向右孩子结点
 * rtag 为 TagNextNode (1) 时，rchild 指向后继节点
 */
 typedef ThreadTreeNode *ThreadTree;

#endif /* TREE_H__ */
