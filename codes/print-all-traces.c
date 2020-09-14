#include "tree.h"
#define BiTreeHeightMAX 4096
int trace[BiTreeHeightMAX];
int idx = 0;
/* DFS 深度遍历 */
void PrintAllTraces(BiTree tree)
{
    if (NULL == tree) {
        for (int i = 0; i < idx; i++)
            printf("%d ", trace[i]);
        printf("\n");
        return;
    }
    trace[idx] = tree->data;
    idx++;
    PrintAllTraces(tree->lchild);
    PrintAllTraces(tree->rchild);
    idx--;
}
