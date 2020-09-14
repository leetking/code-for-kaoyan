#include "tree.h"
/**
 * 表达树：叶子节点为数据，非叶子节点为运算符号
 * 实际上就是中序遍历
 */
void PrintExpressionBiTree(BiTree tree)
{
    if (NULL == tree) return;

    /* 操作数 */
    if (NULL == tree->lchild && NULL == tree->rchild) {
        printf("%d", tree->data);
        return;
    }

    printf("(");
    PrintExpressionBiTree(tree->lchild);
    printf("%c", tree->data);   /* 操作符 */
    PrintExpressionBiTree(tree->rchild);
    printf(")");
}
