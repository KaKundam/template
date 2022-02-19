int in[gh],nod[gh],deep[gh],m,Rmin[20][gh],Rnod[20][gh];
void    DFS(int u,int v=0){
	in[u] = ++m;
	nod[m] = u;
	deep[u] = deep[v] + 1;
	for (auto h:adj[u]) if (h != v){
		DFS(h,u);
		nod[++m] = u;
	}
}
void    RMQ(){
	for (int i=1;i<=m;i++) {
		Rmin[0][i] = deep[nod[i]];
		Rnod[0][i] = nod[i];
	}
	for(int k = 1; (1<<k) <= m; ++k)
	for(int i = 1; i + (1<<k) - 1 <= m; ++i){
		if (Rmin[k-1][i] < Rmin[k-1][i + (1<<(k-1))]){
				Rmin[k][i] = Rmin[k-1][i];
				Rnod[k][i] = Rnod[k-1][i];
		}else{
				Rmin[k][i] = Rmin[k-1][i + (1<<(k-1))];
				Rnod[k][i] = Rnod[k-1][i + (1<<(k-1))];
		}
	}
}
int    LCA(int u,int v){
	u = in[u]; v = in[v];
	if (u > v) swap(u,v);
	int k = __lg(v - u + 1);
	if (Rmin[k][u] < Rmin[k][v - (1<<k) + 1])
		return Rnod[k][u];
	return Rnod[k][v - (1<<k) + 1];
}
