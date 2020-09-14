#include"tree.h"
ThreadTree NextNode(ThreadTree node)
{
    /**
     * 注意：和先序遍历寻找前驱类似，也是比较困难，原因一样
     * 如果 node->rtag == TagNextNode，直接返回 node->rchild 即可
     * 否则就是 node 的父节点，父节点难以求得
     */
}
ThreadTree PrevNode(ThreadTree node)
{
    if (TagChild == node->rtag)
        return node->rchild;
    return node->lchild;
}
ThreadTree FirstNode(ThreadTree tree)
{
    if (NULL == tree) return tree;
    /* 第一个节点是“最左边”的第一个叶节点 */
    while (true) {
        if (TagChild == tree->ltag)
            tree = tree->lchild;
        else if (TagChild == tree->rtag)
            tree = tree->rchild;
        else
            break;
    }
    return tree;
}
ThreadTree LastNode(ThreadTree tree)
{
    return tree;
}
void PostOrderOfPostThread(ThreadTree tree)
{
    /**
     * 后序线索树想要后序遍历，因为 NextNode() 函数难以实现，
     * 所以后序遍历也难以实现
     * 但是，逆后序遍历是容易的，下面给出逆后序遍历
     */
    ThreadTree node;
    for (node = LastNode(tree); NULL != node; node = PrevNode(node)) {
        /* 访问节点 */
        //visit(node);
    }
}
