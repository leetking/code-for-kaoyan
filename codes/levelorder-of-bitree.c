void LevelOrder(BiTree tree)
{
#define TreeWidthMax 4096
    if (NULL == tree) return;
    SeqQueue queue;
    InitQueue(&queue, TreeNodesMax);

    EnQueue(&queue, tree);
    while (!QueueEmpty(&queue)) {
        BiTree node;
        DeQueue(&queue, &node);
        /* 访问节点 */
        //visit(node);
        if (NULL != node->lchild)
            EnQueue(&queue, node->lchild);
        if (NULL != node->rchild)
            EnQueue(&queue, node->rchild);
    }

    DestroyQueue(&queue);
}
