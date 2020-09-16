void PreOrder(BiTree tree)
{
#define TreeHeightMax 2048
    SeqStack stack;
    InitStack(&stack, TreeHeightMax);

    BiTree curr = tree;
    while (NULL != curr || !StackEmpty(&stack)) {
        if (NULL != curr) {
            /* 访问当前节点 curr */
            //visit(curr);
            Push(&stack, curr);
            curr = curr->lchild;
        } else {
            Pop(&stack, &curr);
            curr = curr->rchild;
        }
    }

    DestroyStack(&stack);
}
