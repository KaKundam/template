// nhớ sửa long long nếu cần
int it[4*gh];
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
void update(int id,int i,int j,int l,int r)
{
    if (i==j){

        return ;
    }int giua=(i+j)>>1;
    update(id<<1,i,giua,l,r);
    update(id<<1|1,giua+1,j,l,r);
    it[id]=match(it[id<<1],it[id<<1|1]);
}
int get(int id,int i,int j,int l,int r)
{
    if (i>r || j<l) return 0;
    if (i>=l && j<=r) return it[id];
    int giua=(i+j)>>1;
    return match(get(id<<1,i,giua,l,r),get(id<<1|1,giua+1,j,l,r));
}