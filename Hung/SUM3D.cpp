void build(int m,int n,int q)
{
	for (int i=0;i<=m;i++)
		for (int j=0;j<=n;j++)
			for (int t=0;t<=q;t++)
		su[i][j][t]=a[i][j][t]+su[i-1][j-1][t-1]
			+su[i-1][j][t]+su[i][j-1][t]+su[i][j][t-1]
		-su[i-1][j-1][t]-su[i-1][j][t-1]-su[i][j-1][t-1];
}
int get(int i1,int j1,int k1,int i2,int j2,int k2)
{
	return su[i2][j2][k2] - su[i2][j1 - 1][k2]
			- su[i2][j2][k1 - 1] + su[i2][j1 - 1][k1 - 1] -
			(su[i1 - 1][j2][k2] - su[i1 - 1][j1 - 1][k2]
			- su[i1 - 1][j2][k1 - 1] + su[i1 - 1][j1 - 1][k1 - 1]);
}