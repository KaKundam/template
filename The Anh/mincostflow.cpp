#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fod(i,a,b) for(int i=a;i>=b;i--)
#define nmax 200005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
int n,m,k,s,t,f[105][105],c[105][105],pre[105],e[105];
int maxflow = 0,mincost = 0;
ll d[105],cost[105][105];
bool vs[105];
vector<int>p[105];
bool findpath(int s,int t)
{
    fo(i,1,n)
    {
        d[i] = oo;
        pre[i] = 0;
        vs[i] = 0;
    }
    d[s] = 0;
    e[s] = oo;
    vs[s] = 1;
    queue<int>st;
    st.push(s);
    while(!st.empty())
    {
        int u = st.front();
        vs[u] = 0;
        st.pop();
        for(auto v : p[u])
        {
            if(f[u][v] < c[u][v])
            {
                ll uv = (f[u][v] < 0 ? -1 : 1) * cost[u][v];
                if(d[v] > d[u] + uv)
                {
                    d[v] = d[u] + uv;
                    pre[v] = u;
                    if(!vs[v])
                    {
                        vs[v] = 1;
                        st.push(v);
                    }
                }
            }
        }
    }
    return (pre[t] != 0);
}
void xuli(int s,int t)
{
    while(1)
    {
        if(!findpath(s,t))
            break;
        int v = t;
        ll E = oo;
        while(v != s)
        {
            int u = pre[v];
            E = min(E,1LL * (f[u][v] >= 0 ? c[u][v] - f[u][v] : -f[u][v]));
            v = u;
        }
        v = t;
        while(v != s)
        {
            int u = pre[v];
            f[u][v] += E;
            f[v][u] -= E;
            v = u;
        }
        maxflow += E;
        mincost += d[t] * E;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("new.inp","r",stdin);
        freopen("new.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>s>>t;
    fo(i,1,m)
    {
        ll u,v,x,w;
        cin>>u>>v>>x>>w;
        cost[v][u] = cost[u][v] = x;
        c[v][u] = c[u][v] = w;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    n++;
    cost[n][s] = 0;
    c[n][s] = k;
    p[n].push_back(s);
    s = n;
    xuli(s,t);
    if(maxflow < k)
        cout<<-1;
    else
    {
        cout<<mincost<<'\n';
        fo(u,1,n-1)
        fo(v,1,n-1)
        if(f[u][v] > 0)
            cout<<u<<' '<<v<<' '<<f[u][v]<<'\n';
        cout<<"0 0 0";
    }
}
