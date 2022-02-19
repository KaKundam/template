#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 1000005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll mu(ll a,ll b)
{
    if(b == 0)
        return 1;
    ll t = mu(a,b/2);
    t = (t * t) % mod;
    if(b & 1)
        t = (t * a) % mod;
    return t;
}
ll n,gt[2*nmax],inv[2*nmax],m;
ll C(ll n,ll k)
{
    if(k > n)
        return 0;
    return ((gt[n] * inv[n-k])%mod * inv[k])%mod;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("hvso.inp","r",stdin);
        freopen("hvso.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll base = 2e6;
    gt[0] = 1;
    fo(i,1,base)
        gt[i] = (gt[i-1] * i) % mod;
    inv[base] = mu(gt[base],mod-2);
    for(int i = base-1;i >= 0;i--)
        inv[i] = (inv[i+1] * (i+1)) % mod;
    cin>>n;
    ll ans = 0;
    fo(i,0,n)
    {
        if(i%2 == 0)
        {
            ans = (ans+((gt[n]*inv[n-i])%mod*inv[i])%mod*gt[n-i])%mod;
        }
        else
        {
            ans = ((ans-((gt[n]*inv[n-i])%mod*inv[i])%mod*gt[n-i])%mod+mod)%mod;
        }
    }
    cout<<ans;
}
