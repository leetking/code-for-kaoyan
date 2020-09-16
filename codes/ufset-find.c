/**
 * 返回 -1 表示 id 不在任何集合内
 * 返回 >= 0 表示 id 所在集合的代表元素
 */
int Find(UFSet *set,  int id)
{
    if (NULL == set) return -1;
    if (id < 0 || id >= set->capacity) return -1;
    while (true) {
        int parent = set->nodes[id];
        if (parent == id || parent == -1)
            return parent;
        id = parent;
    }
}
