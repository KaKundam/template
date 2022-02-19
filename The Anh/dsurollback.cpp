#include <bits/stdc++.h>
#define ll unsigned long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define ii pair<int,int>
#define iii pair<ll,ii>
#define fi first
#define se second
#define oo 1e18
#define bit(x,i) (((x)>>(i))&1)
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n,q,t[N],u[N],v[N];
int par[N],sz[N];
map<ii,int>f;
vector<ii>st[N<<2];
int root(int u)
{
    return (u == par[u] ? u : root(par[u]));
}
void build(int id,int l,int r,int u,int v,int a,int b)
{
    if(r < u || v < l)
        return ;
    if(u <= l && r <= v)
    {
        st[id].push_back(ii(a,b));
        return ;
    }
    int mid = l + r >> 1;
    build(id<<1,l,mid,u,v,a,b);
    build(id<<1|1,mid+1,r,u,v,a,b);
}
void rollback(int id,int l,int r)
{
    stack<ii>s;
    for(auto x : st[id])
    {
        int u = root(x.fi);
        int v = root(x.se);
        if(u == v)
            continue;
        if(sz[u] < sz[v])
            swap(u,v);
        s.push(ii(v,par[v]));
        s.push(ii(u,sz[u]));
        par[v] = u;
        sz[u] += sz[v];
    }
    if(l == r)
    {
        if(t[l] == 3)
        {
            if(root(u[l]) == root(v[l]))
                cout<<"YES"<<'\n';
            else
                cout<<"NO"<<'\n';
        }
    }
    else
    {
        int mid = l + r >> 1;
        rollback(id<<1,l,mid);
        rollback(id<<1|1,mid+1,r);
    }
    while(!s.empty())
    {
        ii u = s.top();
        s.pop();
        sz[u.fi] = u.se;
        ii v = s.top();
        s.pop();
        par[v.fi] = v.se;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("dsurollback.inp","r",stdin);
        freopen("dsurollback.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fo(i,1,n)
    {
        par[i] = i;
        sz[i] = 1;
    }
    fo(i,1,q)
    {
        cin>>t[i]>>u[i]>>v[i];
        if(u[i] > v[i])
            swap(u[i],v[i]);
        if(t[i] == 1)
            f[{u[i],v[i]}] = i;
        if(t[i] == 2)
        {
            int &j = f[{u[i],v[i]}];
            build(1,1,q,j,i,u[i],v[i]);
            j = 0;
        }
    }
    fo(i,1,q)
    {
        int &j = f[{u[i],v[i]}];
        if(j != 0)
        {
            build(1,1,q,j,q,u[i],v[i]);
            j = 0;
        }
    }
    rollback(1,1,q);
}
