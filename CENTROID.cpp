bool incentroid[gh];
vector<int> adj[gh];
int n,sz[gh],par[gh];
int DFS(int i,int pre=-1)
{
    sz[i]=1;
    for (int h:adj[i])
        if (h!=pre && !incentroid[h]) DFS(h,i),sz[i]+=sz[h];
    return sz[i];
}
int anc(int i,int range,int pre=-1)
{
    for (int h:adj[i])
        if (h!=pre && !incentroid[h] && sz[h]>range/2) return anc(h,range,i);
    return i;
}
void centroid(int i,int pre=-1)
{
    int c=anc(i,DFS(i));
    par[c]=pre;
    incentroid[c]=true;
    for (int h:adj[c])
        if (!incentroid[h]) centroid(h,c);
}