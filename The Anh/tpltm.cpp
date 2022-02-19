#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 200005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll t,n,m,u,v,num[nmax],low[nmax],d[nmax],dem = 0;
vector<int>p[nmax];
bool vs[nmax];
stack<int>s;
void dfs(int u)
{
    num[u] = low[u] = ++num[0];
    s.push(u);
    for(auto v : p[u])
    if(!vs[v])
    {
        if(num[v])
            low[u] = min(low[u],num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
    }
    if(low[u] < num[u])
        return ;
    int x;
    dem++;
    do
    {
        x = s.top();
        d[x] = dem;
        s.pop();
        vs[x] = 1;
    }
    while(x != u);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("new.inp","r",stdin);
        freopen("new.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    fo(i,1,m)
    {
        cin>>u>>v;
        p[u].push_back(v);
    }
    fo(i,1,n)
    if(!vs[i])
        dfs(i);
    cout<<dem<<'\n';
    fo(i,1,n)
        cout<<d[i]<<' ';
}
