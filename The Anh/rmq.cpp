#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 3000005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9+7;
ll n,t,a[nmax],Ma[nmax][30],Mi[nmax][30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    fo(i,1,n)
    {
        cin>>a[i];
        Ma[i][0] = a[i];
        Mi[i][0] = a[i];
    }
    for(int k = 1; (1 << k) <= n;k++)
        for(int i = 1; i + (1<<k) -1 <= n;i++)
        {
            Ma[i][k] = max(Ma[i][k-1],Ma[i+(1<<(k-1))][k-1]);
            Mi[i][k] = min(Mi[i][k-1],Mi[i+(1<<(k-1))][k-1]);
        }
    int l = 1, r = n, ans = 0;
    while(l<=r)
    {
        int mid = l+r>>1;
        int k = log2(mid);
        bool ok = 0;
        fo(i,1,n-mid+1)
        {
            int u = i;
            int v = i + mid - 1;
            ll maxx = max(Ma[u][k],Ma[v - (1<<k) + 1][k]);
            ll minn = min(Mi[u][k],Mi[v - (1<<k) + 1][k]);
            if(maxx - minn <= t)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<ans;
}
