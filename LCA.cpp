int n,lca[30][gh],lv[gh];
vector <int> adj[gh];
void DFS(int i,int pre=-1)
{
    for (auto u:adj[i])
    if (u!=pre){
        lv[u]=lv[i]+1;
        lca[0][u]=i;
        DFS(u,i);
    }
}
void build_LCA()
{
	for (int t=1;t<=20;t++)
		for (int u=1;u<=n;u++)
			lca[t][u]=lca[t-1][lca[t-1][u]];
}
int LCA(int u,int v)
{
    if (lv[u]<lv[v]) swap(u,v);
    int k=lv[u]-lv[v];
    for (int t=20;t>=0;--t)
        if (k>=(1<<t)){
            k-=1<<t;
            u=lca[t][u];
        }
    if (u==v) return u;
    for (int t=20;t>=0;--t)
        if (lca[t][u]!=lca[t][v]) u=lca[t][u],v=lca[t][v];
    return lca[0][v];
}