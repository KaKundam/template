struct Node
{

}it[4*gh];
Node match(Node a,Node b)
{
	Node t;
	return t;
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
void update(int id,int i,int j,int l)
{
	if (i>l || j<l) return ;
	if (i==j){

		return ;
	}int giua=(i+j)>>1;
	update(id<<1,i,giua,l);
	update(id<<1|1,giua+1,j,l);
	it[id]=match(it[id<<1],it[id<<1|1]);
}
Node get(int id,int i,int j,int l,int r)
{
	if (i>r || j<l) return ;
	if (i>=l && j<=r) return it[id];
	int giua=(i+j)>>1;
	return match(get(id<<1,i,giua,l,r),get(id<<1|1,giua+1,j,l,r));
}