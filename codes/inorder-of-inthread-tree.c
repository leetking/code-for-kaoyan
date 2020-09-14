#include "tree.h"
/* 在中序线索树中，求给定节点的后继  */
ThreadTree NextNode(ThreadTree node)
{
    if (TagNextNode == node->rtag)
        return node->rchild;
    /* 右子树的第一个节点就是当前节点的后继节点 */
    return FirstNode(node->rchild);
}
/* 在中序线索树中，求给定节点的前驱 */
ThreadTree PrevNode(ThreadTree node)
{
    if (TagPrevNode == node->ltag)
        return node->lchild;
    /* 左子树的最后一个节点解释当前节点的前驱节点 */
    return LastNode(node->lchild);
}
/* 在中序线索树中，求中序序列第一个节点 */
ThreadTree FirstNode(ThreadTree tree)
{
    if (NULL == tree) return NULL;
    /* 左边“链”往左下的最后一个节点 */
    while (TagPrevNode != tree->ltag)
        tree = tree->lchild;
    return tree;
}
/* 在中序线索树中，求中序序列最后一个节点 */
ThreadTree LastNode(ThreadTree tree)
{
    if (NULL == tree) return NULL;
    /* 右边“链”往右下的最后一个节点 */
    while (TagNextNode != tree->rtag)
        tree = tree->rchild;
    return tree;
}
void InOrderOfInThraedTree(ThreadTree tree)
{
    ThreadTree node;
    for (node = FirstNode(tree);NULL != node; node = NextNode(node)) {
        /* 访问节点 node */
        //visit(node);
    }
    /* 如果是按照中序序列逆序 */
    //for (node = LastNode(tree); NULL != node; node = PrevNode(node)) {
    //    /* 访问节点 node */
    //    //visit(node);
    //}
}
