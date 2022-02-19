#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 100005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
ll t,n,a[nmax],trie[nmax*32][5];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("xor.inp","r",stdin);
        freopen("xor.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(trie,-1,sizeof(trie));
        fo(i,1,n)
            cin>>a[i];
        ll nnode = 1,c,b,r,ans = 0;
        fo(i,1,n-1)
        {
            c = 1;
            for(int j = 29;j >= 0;j--)
            {
                b = ((a[i]>>j)&1);
                if(trie[c][b] == -1)
                {
                    ++nnode;
                    trie[c][b] = nnode;
                }
                c = trie[c][b];
            }
            c = 1;
            r = 0;
            for(int j = 29;j >= 0;j--)
            {
                b = ((a[i+1]>>j)&1);
                if(trie[c][1-b] > -1)
                {
                    r = r | ((1-b) * (1<<j));
                    c = trie[c][1-b];
                }
                else
                {
                    r = r | (b * (1<<j));
                    c = trie[c][b];
                }
            }
            ans = max(ans,a[i+1]^r);
        }
        cout<<ans<<'\n';
    }
}
