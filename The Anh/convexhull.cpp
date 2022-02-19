#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define nmax 100005
using namespace std;
struct point
{
    ll x,y;
};
ll n,sum=0;
point p[nmax],A;
vector<point>q;
ll cp(ll n)
{
    return n*n;
}
ll cmp(point B,point C)
{
    if((B.x-A.x)*(C.y-A.y)==(B.y-A.y)*(C.x-A.x))

        return (cp(B.x-A.x)+cp(B.y-A.y)<cp(C.x-A.x)+cp(C.y-A.y));

    return (B.x-A.x)*(C.y-A.y)>(B.y-A.y)*(C.x-A.x);
}
ll check(point A,point B,point C)
{
    return (B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-B.x)>0;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    fo(i,1,n)
        cin>>p[i].x>>p[i].y;
    int i=1;
    fo(j,2,n)
    if(p[j].y<p[i].y||p[j].y==p[i].y&&p[j].x<p[i].x)
        i=j;
    A=p[i];
    sort(p+1,p+1+n,cmp);
    ll les=0;
    fo(i,1,n)
    {
        while(les>=2&&!check(q[les-2],q[les-1],p[i]))
        {
            les--;
            q.pop_back();
        }
        q.push_back(p[i]);
        les++;
    }
    q.push_back(q[0]);
    cout<<les<<'\n';
    fo(i,0,les-1)
        sum+=(q[i].x*q[i+1].y-q[i].y*q[i+1].x);
    sum=abs(sum);
    cout<<sum/2;
    if(sum&1) cout<<".5"<<'\n';
    else cout<<".0"<<'\n';
    fo(i,0,les-1)
        cout<<q[i].x<<' '<<q[i].y<<'\n';
}
