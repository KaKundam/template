int l[gh],d[gh],p[gh],m,n,kq,id=1;
bool vs[gh],st[gh];
stack <int> stk;
vector <int> adj[gh];
void DFS(int i)
{
    vs[i]=true;
    l[i]=d[i]=id++;
    stk.push(i);
    st[i]=true;
    for (auto u:adj[i]){
        if (!vs[u]){
            DFS(u);
            d[i]=min(d[i],d[u]);
        }else if (st[u]) d[i]=min(d[i],d[u]);
    }
    if (d[i]==l[i]) {
        kq++;
        int u;
        do{
            u=stk.top();
            p[u]=kq;
            stk.pop();
            st[u]=false;
        }while(i!=u);
    }
}