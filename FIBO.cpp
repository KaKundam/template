map <int,int> F;
int f(int n)
{
    if (n<2) return F[n]=n;
    if (F.find(n)!=F.end()) return F[n];
    if (n&1) return F[n]=(1LL*f((n+1)>>1)*F[(n+1)>>1]+1LL*f(n>>1)*F[n>>1])%mod;
    else return F[n]=(1LL*(2LL*f(n/2-1)+f(n>>1))*F[n>>1])%mod;
}