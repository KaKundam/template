// l[i] là điểm đầu tiên bên trái < a[i]
// r[i] tương tự nhưng bên phải
l[0]=0;r[n+1]=n+1;
	for (int i=1;i<=n;i++)
	{
		l[i]=i-1;
		while (l[i]>0 && a[l[i]]>=a[i]) l[i]=l[l[i]];
	}
	for (int i=n;i>=0;--i)
	{
		r[i]=i+1;
		while (r[i]<=n && a[r[i]]>=a[i]) r[i]=r[r[i]];
	}