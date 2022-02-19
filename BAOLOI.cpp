// ans là mảng bao lồi của a
struct Vector
{
    lo x,y;
    Point operator - (const Point v)const {
        return {x-v.x,y-v.y};
    }lo operator * (const Vector v){
        return {x*v.y-v.x*y};
    }
};
double sz(Vector t)
{
    return sqrt(t.y*t.y+t.x*t.x);
}
bool CCW(Point A,Point B,Point C)
{
    return (B-A)*(C-A)>0;
}
int n;
Point A,a[1000006],ans[1000006];
bool hung(Point B,Point C)
{
    Vector ab=B-A;
    Vector ac=C-A;
    if (ab*ac==0) return sz(ab)<sz(ac);
    return (ab*ac>0);
}
int main()
{
    START();
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y;
    int id=1;
    for (int i=2;i<=n;++i)
        if (a[i].y<a[id].y || (a[i].y==a[id].y && a[i].x<a[id].x)) id=i;
    A=a[id];
    sort(a+1,a+1+n,hung);
    id=0;
    for (int i=1;i<=n;i++){
        while(id>1 && !CCW(ans[id-1],ans[id],a[i]))
            --id;
        ans[++id]=a[i];
    }cout<<id<<'\n';
    lo s=0;
    ans[id+1]=ans[1];
    for (int i=1;i<=id;++i)
        s+=ans[i].x*ans[i+1].y-ans[i].y*ans[i+1].x;
    cout<<s/2;
    if (s&1) cout<<".5\n";
    else cout<<".0\n";
    for (int i=1;i<=id;++i)
        cout<<ans[i].x<<' '<<ans[i].y<<'\n';
}