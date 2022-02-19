void build()
{
    for (int i=1;i<=n;++i)
        d[i][i]=0;
    for (int k=1;k<=n;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
    			mini(d[i][j],d[i][k]+d[k][j]);
}
