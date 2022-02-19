int lca(int x,int y)
{
    if(l[x] < l[y])
        swap(x,y);
    for(int k = 16; k >= 0; k--)
    if(l[x] - (1<<k) >= l[y])
         x = P[k][x];
    if(x == y)
        return x;
    for(int k = 16; k >= 0; k--)
    if(P[k][x] != 0 && P[k][x] != P[k][y])
    {
        x = P[k][x];
        y = P[k][y];
    }
    while(x != y)
    {
        x = P[0][x];
        y = P[0][y];
    }
    return x;
}
fo(k,1,16)
fo(i,1,n)
    P[k][i] = P[k-1][P[k-1][i]];
