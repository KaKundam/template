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
ll t,n,trie[nmax][30],node[nmax];
vector<int>ds[nmax],p[nmax];
string s;
stack<int>st;
void dfs(int u)
{
    for(auto k : ds[u])
        st.push(k);
    for(auto v : p[u])
        dfs(v);
    while(st.size() > 1 && node[st.top()] == u)
    {
        cout<<st.top()<<' ';
        st.pop();
        cout<<st.top()<<'\n';
        st.pop();
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("str2n.inp","r",stdin);
        freopen("str2n.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    int nnode = 1,c,b,r;
    fo(i,1,2*n)
    {
        cin>>s;
        int m = s.size();
        s = ' ' + s;
        c = 1;
        fo(j,1,m)
        {
            b = s[j] - 'a' + 1;
            if(trie[c][b] == 0)
            {
                ++nnode;
                trie[c][b] = nnode;
                p[c].push_back(trie[c][b]);
            }
            c = trie[c][b];
        }
        ds[c].push_back(i);
        node[i] = c;
    }
    dfs(1);
}

