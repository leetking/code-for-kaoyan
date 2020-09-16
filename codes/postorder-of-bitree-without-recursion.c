void PostOrder(BiTree tree)
{
#define TreeHeightMax 2048
    SeqStack stack;
    InitStack(&stack, TreeHeightMax);
    BiTree lastVisited = NULL;
    BiTree curr = tree;

    while (NULL != curr || !StackEmpty(&stack)) {
        if (NULL != curr) {
            Push(&stack, curr);
            curr = curr->lchild;
        } else {
            GetTop(&stack, &curr);  /* 只获取栈顶，不弹栈 */
            if (NULL != curr->rchild && lastVisited != curr->rchild) {
                curr = curr->rchild;
            } else {
                /* 访问当前节点 */
                //visit(curr);
                Pop(&stack, &lastVisited);
            }
        }
    }

    DestroyStack(&stack);
}
