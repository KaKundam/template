#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define oo 1e18
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n,sa[N],ra[N],rb[N],k;
char a[N];
bool cmp(int x,int y)
{
    if(ra[x] != ra[y])
        return ra[x] < ra[y];
    return ra[x+k] < ra[y+k];
}
void sufarr()
{
    fo(i,1,n)
    {
        sa[i] = i;
        ra[i] = a[i];
    }
    for(k = 1;k <= n;k *= 2)
    {
        sort(sa+1,sa+1+n,cmp);
        fo(i,1,n)
            rb[sa[i]] = rb[sa[i-1]] + cmp(sa[i-1],sa[i]);
        fo(i,1,n)
            ra[i] = rb[i];
        if(ra[sa[n]] == n)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    fo(i,1,n)
        cin>>a[i];
    sufarr();
}
