template<typename T>
vector<T> dijkstra(int s, vector<vector<pair<int,T>>> adj){
    int n=sz(adj);
    vector<T> dis(n,inf<T>);
    vector<int> vis(n);
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dis[s]=0,pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]: adj[u]) if(d+w<dis[v]){
            dis[v]=d+w;
            pq.push({dis[v],v});
        }
    }
    return dis;
}

