void InOrder(BiTree tree)
{
#define TreeHeightMax 2048
    SeqStack stack;
    InitStack(&stack, TreeHeightMax);

    BiTree curr = tree;
    while (NULL == curr || !StackEmpty(&stack)) {
        if (NULL != curr) {
            Push(&stack, curr);
            curr = curr->lchild;
        } else {
            Pop(&stack, &curr);
            /* 访问节点 node */
            //visit(node);
            curr = curr->rchild;
        }
    }

    DestroyStack(&stack);
}
