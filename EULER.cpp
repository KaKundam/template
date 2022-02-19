bool vs[gh];
vector<int> r;
vector<pair<int,int>> adj[gh];
void DFS(int i)
{
	while(adj[i].size()){
		pair<int,int> u=adj[i].back();
		if (!vs[u.se]) vs[u.se]=true,DFS(u.fi);
		else adj[i].pop_back();
	}if (adj[i].size()==0) r.push_back(i);
}