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
const ll mod = 998244353;
ll n,q,a[nmax],st[4*nmax],lza[4*nmax],lzb[4*nmax];
void build(int id,int i,int j)
{
    if(i == j)
    {
        st[id] = a[i];
        return ;
    }
    int mid = i + j >> 1;
    build(2*id,i,mid);
    build(2*id+1,mid+1,j);
    st[id] = st[2*id] + st[2*id+1];
}
void down(ll id,ll l,ll r)
{
    ll mid = l + r >> 1;
    st[2*id] += lza[id] * (mid*(mid+1)/2 - (l-1)*l/2) + lzb[id] * (mid - l + 1);
    st[2*id+1] += lza[id] * (r*(r+1)/2 - mid*(mid+1)/2) + lzb[id] * (r - mid);
    lza[2*id] += lza[id];
    lza[2*id+1] += lza[id];
    lzb[2*id] += lzb[id];
    lzb[2*id+1] += lzb[id];
    lza[id] = 0;
    lzb[id] = 0;
}
void update(int id,ll l,ll r,ll u,ll v,ll val1,ll val2)
{
    if(r < u || v < l)
        return ;
    if(u <= l && r <= v)
    {
        st[id] += val1 * (r*(r+1)/2 - (l-1)*l/2) + val2 * (r-l+1);
        lza[id] += val1;
        lzb[id] += val2;
        return ;
    }
    down(id,l,r);
    ll mid = l + r >> 1;
    update(2*id,l,mid,u,v,val1,val2);
    update(2*id+1,mid+1,r,u,v,val1,val2);
    st[id] = st[2*id] + st[2*id+1];
}
ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(r < u || v < l)
        return 0;
    if(u <= l && r <= v)
        return st[id];
    down(id,l,r);
    ll mid = l + r >> 1;
    return get(2*id,l,mid,u,v) + get(2*id+1,mid+1,r,u,v);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("new.inp","r",stdin);
        freopen("new.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fo(i,1,n)
        cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t == 1)
            update(1,1,n,l,r,1,1-l);
        else
            cout<<get(1,1,n,l,r)<<'\n';
    }
}
