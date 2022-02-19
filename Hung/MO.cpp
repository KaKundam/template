int n,a[30006],pre[30006],d[1000006],kq,ans[200006];
struct query
{
    int l,r,pos;
    lo ord;

    lo gilbertOrder(int x, int y, int pow, int rotate) {
        if (pow == 0) {
            return 0;
        }
        int hpow = 1 << (pow-1);
        int seg = (x < hpow) ? (
            (y < hpow) ? 0 : 3
        ) : (
            (y < hpow) ? 1 : 2
        );
        seg = (seg + rotate) & 3;
        const int rotateDelta[4] = {3, 0, 0, 1};
        int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
        int nrot = (rotate + rotateDelta[seg]) & 3;
        lo subSquareSize = (lo)(1) << (2*pow - 2);
        lo ans = seg * subSquareSize;
        lo add = gilbertOrder(nx, ny, pow-1, nrot);
        ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
        return ans;
    }
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
    bool operator < (const query a)const{
        return ord<a.ord;
    }
}q[200006];
void update(bool them,int x)
{
    if (them==1){
        d[x]++;
        if (d[x]==1) kq++;
    }
    else {
        d[x]--;
        if (d[x]==0) kq--;
    }
}
int main()
{
    START();
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int T;
    cin>>T;
    for (int i=1;i<=T;++i){
        int &l=q[i].l,&r=q[i].r;
        cin>>l>>r;
        q[i].pos=i;
        q[i].calcOrder();
    }
    sort(q+1,q+1+T);
    for (int i=q[1].l;i<=q[1].r;++i)
        update(1,a[i]);
    ans[q[1].pos]=kq;
    int L=q[1].l,R=q[1].r;
    for (int i=2;i<=T;++i)
    {
        for (;L>q[i].l;--L)
            update(1,a[L-1]);
        for (;L<q[i].l;L++)
            update(0,a[L]);
        L=q[i].l;
        for (;R<q[i].r;R++)
            update(1,a[R+1]);
        for (;R>q[i].r;--R)
            update(0,a[R]);
        R=q[i].r;
        ans[q[i].pos]=kq;
    }
    for (int i=1;i<=T;++i)
        cout<<ans[i]<<'\n';
}
