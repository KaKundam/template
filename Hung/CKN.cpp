int gt[gh],inv[gh];
void prepare(int n)
{
	gt[0]=1;
	for (lo i=1;i<=n;++i)
		gt[i]=(gt[i-1]*i)%mod;
	inv[n]=mu(gt[n],mod-2);
	for (lo i=n-1;i>=0;--i)
		inv[i]=(inv[i+1]*(i+1))%mod;
}
inline int C(int n,int k)
{
	if (k>n) return 0;
	return ((1LL*gt[n]*inv[k])%mod*inv[n-k])%mod;
}

// mod ko ngto
int g[gh],d[gh];
void prepare(int n)
{
    for (int i=2;i<=n;i++)
	    if (g[i]==0) for (int j=i;j<=n;j+=i)
            g[j]=i;
}
int C(int n,int k,int m=mod)
{
	for (int i=n-k+1;i<=n;i++)
	{
        int h=i;
        while(h>1){
            d[g[h]]++;
            h/=g[h];
        }
    }
	for (int i=1;i<=k;i++)
    {
        int h=i;
        while(h>1){
            d[g[h]]--;
            h/=g[h];
        }
    }lo kq=1;
    for (int i=1;i<=n;i++)
        kq=(kq*mu(i,d[i]))%m;
    return kq;
}