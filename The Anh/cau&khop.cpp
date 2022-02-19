#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e4 + 5;
int n,m,num[N],low[N],par[N],child[N];
int cau = 0,khop[N],cnt = 0;
vector<int>p[N];
void dfs(int u)
{
    num[u] = low[u] = ++cnt;
    for(auto v : p[u])
    {
        if(!num[v])
        {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else
        {
            if(v != par[u])
                low[u] = min(low[u],num[v]);
        }
    }
}
int findkhop()
{
    fo(v,1,n)
    {
        int u = par[v];
        child[u]++;
        if(par[u] > 0 && low[v] >= num[u])
            khop[u] = 1;
    }
    fo(u,1,n)
    if(!par[u])
        khop[u] = (child[u] > 1);
    fo(i,1,n)
        khop[0] += khop[i];
    return khop[0];
}
int findcau()
{
    fo(v,1,n)
    {
        int u = par[v];
        if(u > 0 && low[v] > num[u])
            cau++;
    }
    return cau;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    fo(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fo(i,1,n)
    if(!num[i])
        dfs(i);
    cout<<findkhop()<<' '<<findcau();
}
