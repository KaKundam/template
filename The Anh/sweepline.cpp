#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
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
const int N = 3e5 + 5;
int t,m,n;
int y[N],l[N],r[N];
int x[N],u[N],d[N];
ii node,line;
ii st[N<<2];
vector<ii>event[N],seg[N];
ii mix(ii a,ii b)
{
    if(a.fi > b.fi)
        return a;
    if(a.fi < b.fi)
        return b;
    return ii(a.fi,max(a.fi,a.se));
}
void up(int id,int l,int r,int p,int k)
{
    if(r < p || p < l)
        return ;
    if(l == r)
    {
        st[id].fi += k;
        st[id].se = p;
        return ;
    }
    int mid = l + r >> 1;
    up(id<<1,l,mid,p,k);
    up(id<<1|1,mid+1,r,p,k);
    st[id] = mix(st[id<<1],st[id<<1|1]);
}
ii get(int id,int l,int r,int u,int v)
{
    if(v < l || r < u)
        return ii(0,0);
    if(u <= l && r <= v)
        return st[id];
    int mid = l + r >> 1;
    ii a = get(id<<1,l,mid,u,v);
    ii b = get(id<<1|1,mid+1,r,u,v);
    return mix(a,b);
}
bool check(int mid)
{
    memset(st,0,sizeof(st));
    fo(i,1,3e5)
    {
        event[i].clear();
        seg[i].clear();
    }
    fo(i,1,m)
    {
        if(r[i] - l[i] < 2*mid)
            continue;
        event[l[i]+mid].push_back(ii(y[i],1));
        event[r[i]-mid+1].push_back(ii(y[i],-1));
    }
    fo(i,1,n)
    {
        if(d[i] - u[i] < 2*mid)
            continue;
        seg[x[i]].push_back(ii(u[i]+mid,d[i]-mid));
    }
    fo(i,1,3e5)
    {
        for(auto k : event[i])
            up(1,1,3e5,k.fi,k.se);
        for(auto k : seg[i])
        {
            ii u = get(1,1,3e5,k.fi,k.se);
            if(u.fi > 0)
            {
                node = ii(i,u.se);
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    int L = 1,R = 3e5,ans;
    while(L <= R)
    {
        int mid = L + R >> 1;
        if(check(mid))
        {
            ans = mid;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    fo(i,1,m)
    if(y[i] == node.se && l[i] + ans <= node.fi && node.fi <= r[i] - ans)
        line.fi = i;
    fo(i,1,n)
    if(x[i] == node.fi && u[i] + ans <= node.se && node.se <= d[i] - ans)
        line.se = i;
    cout<<ans<<' '<<line.fi<<' '<<line.se;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("collider.inp","r",stdin);
        freopen("collider.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);;
    cin>>t>>m>>n;
    fo(i,1,m)
    {
        cin>>y[i]>>l[i]>>r[i];
        if(l[i] > r[i])
            swap(l[i],r[i]);
    }
    fo(i,1,n)
    {
        cin>>x[i]>>u[i]>>d[i];
        if(u[i] > d[i])
            swap(u[i],d[i]);
    }
    solve();
}


