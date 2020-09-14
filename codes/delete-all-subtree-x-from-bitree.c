#include "tree.h"
void DestroyBiTree(BiTree tree)
{
    if (NULL == tree) return;
    DestroyBiTree(tree->lchild);
    DestroyBiTree(tree->rchild);
    free(tree);
}
void DeleteAllSubtreeXFromBiTree(BiTree *ptree, int x)
{
    if (NULL == ptree || NULL == *ptree) return;
    if (x == (*ptree)->data) {
        DestroyBiTree(*ptree);
        *ptree = NULL;
        return;
    }
    DeleteAllSubtreeXFromBiTree(&(*ptree)->lchild, x);
    DeleteAllSubtreeXFromBiTree(&(*ptree)->rchild, x);
}
