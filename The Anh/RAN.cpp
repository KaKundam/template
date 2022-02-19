#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 200005
#define ii pair<int,int>
#define fi first
#define se second
#define oo 1e9
using namespace std;
const int mod = 1e9+7;
int a[105][105];
ll Rand(ll l ,ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX+1) +
            (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
            (ll)rand() * (RAND_MAX + 1) +
            rand()) %  (h - l + 1);
}
int main()
{
    freopen("ran.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    srand(time(NULL));
    Sleep(1000);
    int n = Rand(10,1e4);
    cout<<n<<'\n';
    fo(i,1,n)
        cout<<Rand(100,1e15)<<' ';
}
