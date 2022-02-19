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
ll t,n,q,a[nmax],st[4*nmax],lz1[4*nmax],lz2[4*nmax];
void down(ll id,ll l,ll r)
{
    ll mid = l + r >> 1;
    if(lz2[id])
    {
        st[2*id] = (mid - l + 1) * lz1[id];
        st[2*id+1] = (r - mid) * lz1[id];
        lz1[2*id] = lz1[id];
        lz1[2*id+1] = lz1[id];
        lz2[2*id] = 1;
        lz2[2*id+1] = 1;
    }
    else
    {
        st[2*id] += (mid - l + 1) * lz1[id];
        st[2*id+1] += (r - mid) * lz1[id];
        lz1[2*id] += lz1[id];
        lz1[2*id+1] += lz1[id];
    }
    lz1[id] = 0;
    lz2[id] = 0;
}
void update(ll type,ll id,ll l,ll r,ll u,ll v,ll k)
{
    if(r < u || v < l)
        return ;
    if(u <= l && r <= v)
    {
        if(type == 0)
        {
            st[id] += (r - l + 1) * k;
            lz1[id] += k;
        }
        else
        {
            st[id] = (r - l + 1) * k;
            lz1[id] = k;
            lz2[id] = 1;
        }
        return ;
    }
    down(id,l,r);
    ll mid = l + r >> 1;
    update(type,2*id,l,mid,u,v,k);
    update(type,2*id+1,mid+1,r,u,v,k);
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
        freopen("Range Updates and Sums.inp","r",stdin);
        freopen("Range Updates and Sums.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    fo(i,1,n)
    {
        cin>>a[i];
        update(1,1,1,n,i,i,a[i]);
    }
    while(q--)
    {
        ll type,l,r,x;
        cin>>type>>l>>r;
        if(type == 1)
        {
            cin>>x;
            update(0,1,1,n,l,r,x);
        }
        if(type == 2)
        {
            cin>>x;
            update(1,1,1,n,l,r,x);
        }
        if(type == 3)
            cout<<get(1,1,n,l,r)<<'\n';
    }
}

