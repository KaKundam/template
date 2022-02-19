#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 400005
#define ii pair<ll,ll>
#define fi first
#define se second
#define oo 1e18
#define ar array
using namespace std;
const int mod = 1e9 + 7;
struct cmp1
{
    bool operator() (ii a,ii b)
    {
        if (a.fi == b.fi) return a.se > b.se;
        return a.fi > b.fi;
    }
};
struct cmp2
{
    bool operator() (ii a,ii b)
    {
        if (a.fi == b.fi) return a.se < b.se;
        return a.fi < b.fi;
    }
};
ll m,n,t,c[nmax];
ll a[nmax],b[nmax],h[nmax];
vector<ii>p[nmax];
vector<ll>p1[nmax];
multiset<ii,cmp1>s1;
multiset<ii,cmp2>s2;
map<ii,int>f;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("smithy.inp","r",stdin);
        freopen("smithy.out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    fo(i,1,n)
        cin>>a[2*i-1]>>a[2*i]>>c[i];
    fo(i,1,2*n)
        h[i] = a[i];
    sort(h+1,h+1+2*n);
    fo(i,1,2*n)
        b[i] = lower_bound(h+1,h+1+2*n,a[i]) - h;
    fo(i,1,n)
    {
        p[b[2*i-1]].push_back({c[i],b[2*i]});
        p1[b[2*i]].push_back(c[i]);
    }
    fo(i,1,2*n)
        h[i] = b[i];
    fo(i,1,2*n)
        b[h[i]] = a[i];
    sort(h+1,h+1+2*n);
    ll q = unique(h+1,h+1+2*n) - h - 1;
    ll ans1 = 0,ans2 = 0,tmp = 0;
    fo(i,1,q)
    {
        while(!s2.empty())
        {
            auto it = s2.begin();
            if(s1.size() < m)
            {
                tmp += (*it).fi;
                s1.insert({(*it).fi,(*it).se});
                s2.erase(it);
            }
            else
            {
                auto it2 = s1.begin();
                if((*it).fi < (*it2).fi)
                {
                    tmp -= (*it2).fi;
                    tmp += (*it).fi;
                    s2.insert({(*it2).fi,(*it2).se});
                    s1.insert({(*it).fi,(*it).se});
                    s2.erase(it);
                    s1.erase(it2);
                }
                else
                    break;
            }
        }
        if(i == 1)
        {
            ans1 += tmp;
            ans2 += s1.size();
        }
        else
        {
            ans1 += tmp * (b[h[i]] - b[h[i-1]] - 1);
            ans2 += s1.size() * (b[h[i]] - b[h[i-1]] - 1);
        }
        for(auto u : p[h[i]])
            s2.insert({u.fi,u.se});
        while(!s2.empty())
        {
            auto it = s2.begin();
            if(s1.size() < m)
            {
                tmp += (*it).fi;
                s1.insert({(*it).fi,(*it).se});
                s2.erase(it);
            }
            else
            {
                auto it2 = s1.begin();
                if((*it).fi < (*it2).fi)
                {
                    tmp -= (*it2).fi;
                    tmp += (*it).fi;
                    s2.insert({(*it2).fi,(*it2).se});
                    s1.insert({(*it).fi,(*it).se});
                    s2.erase(it);
                    s1.erase(it2);
                }
                else
                    break;
            }
        }
        ans1 += tmp;
        ans2 += s1.size();
        for(auto u : p1[h[i]])
        {
            ii k = {u,h[i]};
            auto x = s1.find(k);
            if(x != s1.end())
            {
                tmp -= u;
                s1.erase(x);
            }
            x = s2.find(k);
            if(x != s2.end())
                s2.erase(x);
        }
    }
    cout<<ans2<<' '<<ans1;
}
