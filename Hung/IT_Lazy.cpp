// nhớ sửa long long nếu cần
int it[4*gh],lazy[4*gh];
void down(int L,int R,int &x)
{
    it[L];lazy[L];
    it[R];lazy[R];
    x=0;
}
int match(int a,int b)
{
    return
}
void build(int id,int i,int j)
{
    if (i==j){

        return ;
    }int giua=(i+j)>>1;
    build(id<<1,i,giua);
    build(id<<1|1,giua+1,j);
    it[id]=match(it[id<<1],it[id<<1|1]);
}
void update(int id,int i,int j,int l,int r,int val)
{
    if (i>r || j<l) return ;
    if (i>=l && j<=r){

        return ;
    }int giua=(i+j)>>1;
    down(id<<1,id<<1|1,lazy[id]);
    update(id<<1,i,giua,l,r,val);
    update(id<<1|1,giua+1,j,l,r,val);
    it[id]=match(it[id<<1],it[id<<1|1]);
}
int get(int id,int i,int j,int l,int r)
{
    if (i>r || j<l) return 0;
    if (i>=l && j<=r) return it[id];
    int giua=(i+j)>>1;
    down(id<<1,id<<1|1,lazy[id]);
    return match(get(id<<1,i,giua,l,r),get(id<<1|1,giua+1,j,l,r));
}