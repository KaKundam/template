int rrhoa(int n,int a[])
{
    pair<int,int> tmp[n+6];
    for (int i=1;i<=n;++i)
        tmp[i]={a[i],i};
    sort(tmp+1,tmp+1+n);
    int D=0,cuoi=INT_MAX;
    for (int i=1;i<=n;++i){
        if (cuoi!=tmp[i].fi) D++,cuoi=tmp[i].fi;
        a[tmp[i].se]=D;
    }return D;
}
	
int rrhoa(int n,pair<int,int> a[])
{
    int id=0;
    pair<pair<int,int>,bool> tmp[2*n+6];
    for (int i=1;i<=n;++i){
        tmp[++id]={{a[i].fi,i},0};
        tmp[++id]={{a[i].se,i},1};
    }sort(tmp+1,tmp+1+id);
    int D=0,cuoi=1e9;
    for (int i=1;i<=id;++i){
        if (cuoi!=tmp[i].fi.fi) D++,cuoi=tmp[i].fi.fi;
        if (tmp[i].se) a[tmp[i].fi.se].se=D;
        else a[tmp[i].fi.se].fi=D;
    }
    return D;
}
	
// rời rạc hóa không bằng


	for (int i=1;i<=n;++i)
		tmp[i]={a[i],i};
	sort(tmp+1,tmp+1+n);
	for (int i=1;i<=n;++i)
		a[tmp[i].se]=i;