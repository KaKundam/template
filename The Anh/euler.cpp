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
ll n,m,eu[nmax],ev[nmax],ind[nmax],out[nmax];
vector<int>p[nmax],ans;
bool vs[nmax];
void dfs(int u = 1)
{
    while(p[u].size())
    {
        int e = p[u].back();
        p[u].pop_back();
        if(vs[e])
            continue;
        vs[e] = 1;
        dfs(eu[e]^ev[e]^u);
        ans.push_back(eu[e]^ev[e]^u);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("euler.inp","r",stdin);
        freopen("euler.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    fo(i,1,m)
    {
        cin>>eu[i]>>ev[i];
        p[eu[i]].push_back(i);
        ind[ev[i]]++;
        out[eu[i]]++;
    }
    fo(i,1,n)
    {
        if(i == 1 && out[i] != ind[i] + 1)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(i == n && ind[i] != out[i] + 1)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(i > 1 && i < n && ind[i] != out[i])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    dfs();
    if(ans.size() != m)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    reverse(ans.begin(),ans.end());
    cout<<1<<' ';
    for(auto u : ans)
        cout<<u<<' ';
}
//do thi ko co khuyen va da canh