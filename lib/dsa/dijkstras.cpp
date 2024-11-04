template<typename T>
vector<T> dijkstra(int start, vector<vector<pair<int,T>>> &adj){
    int n=sz(adj);
    vector<T> dist(n,4e18); //change if needed
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dist[start]=0, pq.push({0,start});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto &[v,w]: adj[u]) if(ckmin(dist[v],d+w)){
            pq.push({dist[v],v});
        }
    }
    return dist;
}

