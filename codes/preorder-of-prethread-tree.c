#include "tree.h"
/* 在先序序列中，找给定节点的后继元素 */
ThreadTree NextNode(ThreadTree node)
{
    if (TagChild == node->ltag)
        return node->lchild;
    return node->rchild;
}
/* 在先序序列中，找给定节点的前驱元素 */
ThreadTree PrevNode(ThreadTree node)
{
    /**
     * 注意：比较困难，可能需要遍历整棵树
     * 因为，如果 node->ltag == TagPrevNode，
     *           只需要返回 node->lchild
     *       否则前驱节点就是 node 的父节点，
     *       然而在二叉树孩子节点表示法中，难以找到父节点
     */
}
/* 在先序线索树中，找先序序列的最后一个节点 */
ThreadTree LastNode(ThreadTree tree)
{
    ThreadTree nextNode;
    while (true) {
        nextNode = NextNode(tree);
        if (NULL == nextNode)
            return tree;
        tree = nextNode;
    }
}
/* 在先序线索树中，找先序序列的第一个节点 */
ThreadTree FirstNode(ThreadTree tree)
{
    return tree;
}
void PreOrderOfPreThreadTree(ThreadTree tree)
{
    /**
     * 把线索化后的节点看成可以通过 PrevNode() 找到前驱和 NextNode() 找到后继的
     * 非循环双链表，如果某一个节点 PrevNode() 为 NULL，说明这个节点为第一个节
     * 点；同理，如果 NextNode() 为 NULL，说明这个节点为最后一个节点
     */
    ThreadTree node;
    for (node = FirstNode(tree); NULL != node; node = NextNode(node)) {
        /* 访问节点 */
        //visit(node);
    }
}
