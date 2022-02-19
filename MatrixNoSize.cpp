// mod long long thì ko dùng được code này
const int sz=;
struct Matrix
{
    int x[sz+1][sz+1];
};
Matrix cong(Matrix a,Matrix b)
{
    Matrix c;
    for (int i=1;i<=sz;++i)
        for (int j=1;j<=sz;++j)
            c.x[i][j]=(a.x[i][j]+b.x[i][j])%mod;
    return c;
}
Matrix nhan(Matrix a,Matrix b)
{
    Matrix c;
    for (int i=1;i<=sz;++i)
        for (int j=1;j<=sz;++j)
    {
        c.x[i][j]=0;
        for (int t=1;t<=sz;++t)
            c.x[i][j]=(c.x[i][j]+1LL*a.x[i][t]*b.x[t][j])%mod;
        if (c.x[i][j]<0) c.x[i][j]+=mod;
    }
    return c;
}

Matrix mu(Matrix a,lo x)
{
	assert(x>0);
	Matrix c=a;
	for (--x;x;x>>=1,a=nhan(a,a))
		if (x&1) b=nhan(b,a);
	return c;
}
// f[1]=1,f[2]=1;
lo f(lo n)
{
    Matrix kq;
    kq.x[1][1]=1;kq.x[1][2]=1;
    kq.x[2][1]=1;kq.x[2][2]=0;
    kq=mu(kq,n-1);
    return kq.x[1][1]%mod;
}
// tinh a.x + a.x^2 + a.x^3 + ...
Matrix kq(Matrix a,lo n)
{
    if (n==1) return a;
    Matrix p=kq(a,n/2);
    p=cong(p,nhan(p,mu(a,n/2)));
    return (n%2==0) ? p:cong(p,mu(a,n));
}