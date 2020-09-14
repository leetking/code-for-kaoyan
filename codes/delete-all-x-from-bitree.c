#include "tree.h"
/**
 * 从二叉树中取下某一个节点，存储到 store 指向的空间里
 */
bool StealNodeFromBiTree(BiTree *ptree, BiTree *store)
{
    /* 空树，没节点可取 */
    if (NULL == *ptree) return false; 
    if (NULL != (*ptree)->lchild)
        return StealNodeFromBiTree(&(*ptree)->lchild, store);
    if (NULL != (*ptree)->rchild)
        return StealNodeFromBiTree(&(*ptree)->rchild, store);
    /* 只有根节点 */
    *store = *ptree;
    *ptree = NULL;
    return true;
}
void DeleteAllXFromBiTree(BiTree *ptree, int x)
{
    if (NULL == ptree || NULL == *ptree) return;

    DeleteAllXFromBiTree(&(*ptree)->lchild, x);
    DeleteAllXFromBiTree(&(*ptree)->rchild, x);

    if (x == (*ptree)->data) {
        BiTree lsubtree = (*ptree)->lchild;
        BiTree rsubtree = (*ptree)->rchild;
        free(*ptree);

        /* 从左子树或者右子树偷一个节点来替代被删除的根节点 */
        BiTree node;
        if (StealNodeFromBiTree(&lsubtree, &node)
                || StealNodeFromBiTree(&rsubtree, &node)) {
            *ptree = node;
            (*ptree)->lchild = lsubtree;
            (*ptree)->rchild = rsubtree;
            return;
        }
        /* 左右子树都没有节点可偷，说明这棵树只有一个节点，直接删除即可 */
        *ptree = NULL;
    }
}
