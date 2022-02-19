int n,m,Low[gh],Num[gh],kh,ca,id;
vector<int> adj[gh];
bool khop[gh];
inline bool cau(int u,int v)
{
	if (Num[u]>Num[v]) // u la con cua v
		return Low[u]>=Num[u];
	return Low[v]>=Num[v];
}
void DFS(int i,int pre=-1,int con=0)
{
	Low[i]=Num[i]=++id;
	for (int h:adj[i]){
		if (!Num[h]) {
			++con;
			DFS(h,i);
			if (pre!=-1) khop[i]|=Low[h]>=Num[i];
			Low[i]=min(Low[i],Low[h]);
		}
		else if (h!=pre) Low[i]=min(Low[i],Num[h]);
	}
	if (pre==-1) khop[i]=con>=2;
}