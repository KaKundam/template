
// mod là int thì để int
// a>mod thì nhớ mod
//mod ở đoạn gọi hàm á
// mu(a%mod,b) á
int mu(int a,lo b)
{
    int c=1;
    for (;b;a=(1LL*a*a)%mod,b>>=1)
	    if (b&1) c=(1LL*c*a)%mod;
    return c;
}



// mod là long long thì để long long
lo mu(lo a,lo b)
{
    lo c=1;
    for (;b;a=na(a,a),b>>=1)
	if (b&1) c=na(c,a);
    return c;
}