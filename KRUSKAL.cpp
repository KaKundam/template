lo kq;
vector<int> adj[gh];
int fa[gh],n,m,r;
struct edge
{
    int u,v,w;
    bool operator < (const edge &a)const{
        return w<a.w;
    }
}d[gh];
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
int main()
{
    START();
    cin>>n>>m;
    for (int i=1;i<=1e5;i++)
        fa[i]=i;
    for (int i=1;i<=m;i++)
        cin>>d[i].u>>d[i].v>>d[i].w;
    sort(d+1,d+1+m);
    for (int i=1;i<=m;i++)
        if (join(d[i].u,d[i].v)) kq+=d[i].w;
    cout<<kq;
}