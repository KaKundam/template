#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define nmax 30005
#define nmax2 65000000
#define ii pair<int,int>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int mod = 1e9 + 7;
int n,a[nmax],q,x,u,v,k,bit[175][nmax],sq;
void update(int t,int m,int val)
{
    while(m > 0)
    {
        bit[t][m] += val;
        m -= m & -m;
    }
}
ll get(int t,int m)
{
    ll tmp = 0;
    while(m < 10005)
    {
        tmp += bit[t][m];
        m += m & -m;
    }
    return tmp;
}
ll query(int l,int r,int val)
{
    int blockl = l/sq;
    int blockr = r/sq;
    ll res = 0;
    if(blockl < blockr)
    {
        fo(i,l,sq*(blockl+1)-1)
            res += (a[i] > val);
        fo(i,sq*blockr,r)
            res += (a[i] > val);
        fo(i,blockl+1,blockr-1)
            res += get(i,val+1);
        return res;
    }
    fo(i,l,r)
        res += (a[i] > val);
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("new.inp","r",stdin);
        freopen("new.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    sq = sqrt(n);
    fo(i,1,n)
    {
        cin>>a[i];
        update(i/sq,a[i],1);
    }
    cin>>q;
    while(q--)
    {
        cin>>x;
        if(x == 0)
        {
            cin>>u>>v;
            update(u/sq,a[u],-1);
            a[u] = v;
            update(u/sq,a[u],1);
        }
        else
        {
            cin>>u>>v>>k;
            cout<<query(u,v,k)<<'\n';
        }
    }
}