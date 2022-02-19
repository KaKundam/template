// nhớ gán fa[i]=i
int fa[gh];
inline int anc(int i)
{
    return (i==fa[i]) ? i:fa[i]=anc(fa[i]);
}
bool join(int u,int v)
{
    u=anc(u);
    v=anc(v);
    if (u==v) return false;
    fa[u]=v;
    return true;
}