int RMQ[23][gh];
void build(int n,int a[])
{
    for (int i=1;i<=n;++i)
        RMQ[0][i]=a[i];
    for (int k=1;(1<<k)<=n;++k)
        for (int i=1;i+(1<<k)-1<=n;++i)
            RMQ[k][i]=min(RMQ[k-1][i],RMQ[k-1][i+(1<<(k-1))]);
}
inline int get(int u,int v)
{
    int k=log2(v-u+1);
    return min(RMQ[k][u],RMQ[k][v-(1<<k)+1]);
}