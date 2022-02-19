priority_queue <pair<lo,int>,vector<pair<lo,int>>,greater<pair<lo,int>>> q;
void dijkstra(int s)
{
    rs(d,66);
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        pair<lo,int> dd=q.top();
        q.pop();
        int i=dd.se;
        if (dd.fi!=d[i]) continue;
        for (auto u:adj[i]){
            int h=u.fi;
            if (mini(d[h],d[i]+u.se)) q.push({d[h],h});
        }
    }
}
priority_queue <pair<lo,int>,vector<pair<lo,int>>,greater<pair<lo,int>>> q;
lo dijkstra(int s,int t)
{
    rs(d,66);
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        pair<lo,int> dd=q.top();
        q.pop();
        int i=dd.se;
        if (dd.fi!=d[i]) continue;
        for (auto u:adj[i]){
            int h=u.fi;
            if (mini(d[h],d[i]+u.se)) q.push({d[h],h});
        }
    }return d[t];
}
priority_queue <pair<lo,int>,vector<pair<lo,int>>,greater<pair<lo,int>>> q;
void dijkstra(int s)
{
    d[s][s]=0;
    q.push({0,s});
    while(q.size()){
        pair<lo,int> dd=q.top();
        q.pop();
        int i=dd.se;
        if (dd.fi!=d[s][i]) continue;
        for (auto u:adj[i]){
            int h=u.fi;
            if (mini(d[s][h],d[s][i]+u.se)) q.push({d[s][h],h});
        }
    }
}
