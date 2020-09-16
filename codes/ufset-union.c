bool Union(UFSet *set, int x, int y)
{
    int xparent = Find(set, x);
    int yparent = Find(set, y);
    if (-1 == xparent || -1 == yparent)
        return false;
    /* y 所在集合的代表元素 yparent 指向 x 集合代表元素 xparent */
    set->nodes[yparent] = xparent;
    return true;
}
