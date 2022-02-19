void build(int m,int n)
{
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			su[i][j]=su[i-1][j]+su[i][j-1]+a[i][j]-su[i-1][j-1];
}
lo get(int u,int v,int x,int y)
{
	return su[x][y]-su[u-1][y]-su[x][v-1]+su[u-1][v-1];
}