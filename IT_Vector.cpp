const int gh=2e5+6;
struct Node
{
    vector <int> v;
    Node(){
        v.clear();
    }
    Node(int sz,int a){
        v.resize(sz);
        for (int &x:v) x=a;
    }
    void up(Node &a,Node &b){
        v.resize(a.v.size()+b.v.size());
        unsigned int i,j,k;
        for (i=j=k=0;i<a.v.size() && j <b.v.size();++k)
            v[k]=(a.v[i]<=b.v[j]) ? a.v[i++]:b.v[j++];
        while(i<a.v.size()) v[k++]=a.v[i++];
        while(j<b.v.size()) v[k++]=b.v[j++];
    }
    int srch(int &x)
    {
        int dau=0,cuoi=v.size()-1,kq=INT_MAX;
        while(dau<=cuoi){
            int giua=(dau+cuoi)>>1;
            if (v[giua]>=x){
                kq=v[giua];
                cuoi=giua-1;
            }else dau=giua+1;
        }return kq;
    }
}it[4*gh];
int n,a[gh];
void build(int id,int i,int j)
{
    if (i==j){
        it[id]=Node(1,a[i]);
        return ;
    }int giua=(i+j)>>1;
    build(id<<1,i,giua);
    build(id<<1|1,giua+1,j);
    it[id].up(it[id<<1],it[id<<1|1]);
}
int g(int id,int i,int j,int l,int r,int val)
{
    if (i>r || j<l) return INT_MAX;
    if (i>=l && j<=r) return it[id].srch(val);
    int giua=(i+j)>>1;
    return min(g(id<<1,i,giua,l,r,val),g(id<<1|1,giua+1,j,l,r,val));
}
inline int get(int l,int r,int val)
{
    int x=g(1,1,n,l,r,val);
    return x==INT_MAX ? -1:x;
}