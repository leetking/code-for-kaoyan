void PreOrder(BiTree tree)
{
#define TreeHeightMax 2048
    SeqStack stack;
    InitStack(&stack, TreeHeightMax);

    Push(&stack, tree);
    while (!StackEmpty(&stack)) {
        BiTree node;
        Pop(&stack, &node);
        if (NULL == node)
            continue;
        /* 访问节点 node */
        //visit(node);
        /* 先右节点入栈，然后是左节点入栈 */
        Push(&stack, node->rchild);
        Push(&stack, node->lchild);
    }

    DestroyStack(&stack);
}
