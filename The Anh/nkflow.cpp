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
int n,m,s,t,u,v,w,pre[1005],e[1005];
int c[1005][1005],f[1005][1005];
vector<int>p[1005];
bool findpath(int s,int t)
{
    fo(i,1,n)
        pre[i] = 0;
    pre[s] = -1;
    e[s] = 1e9;
    queue<int>st;
    st.push(s);
    while(!st.empty())
    {
        int u = st.front();
        st.pop();
        for(auto v : p[u])
        {
            if(pre[v] == 0 && f[u][v] < c[u][v])
            {
                pre[v] = u;
                e[v] = min(e[u],c[u][v] - f[u][v]);
                st.push(v);
                if(v == t)
                    return true;
            }
        }
    }
    return false;
}
void xuli(int s,int t)
{
    while(1)
    {
        if(!findpath(s,t))
            break;
        int v = t,E = e[t];
        while(v != s)
        {
            int u = pre[v];
            f[u][v] += E;
            f[v][u] -= E;
            v = u;
        }
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
    cin>>n>>m>>s>>t;
    fo(i,1,m)
    {
        cin>>u>>v>>w;
        p[u].push_back(v);
        p[v].push_back(u);
        c[u][v] = w;
    }
    xuli(s,t);
    ll ans = 0;
    for(auto u : p[s])
        ans += f[s][u];
    cout<<ans;
}