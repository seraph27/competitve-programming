struct hopcroftkarp {
    int nL, nR;
    vector<vector<int>> adj;
    vector<int> matchL, matchR, dist;

    hopcroftkarp(int nL, int nR) : nL(nL), nR(nR), adj(nL), matchL(nL, -1), matchR(nR, -1), dist(nL) {}

    void add_edge(int u, int v) {
        adj[u].pb(v);
    }

    bool bfs() {
        queue<int> q;
        bool reachableR = false;
        fill(all(dist), -1);
        for(int u = 0; u < nL; u++) if(matchL[u] == -1) dist[u] = 0, q.push(u);
        while(!q.empty()) {
            auto f = q.front(); q.pop();
            for(auto &e : adj[f]) {
                int v = matchR[e];
                if(v == -1) reachableR = true;
                else if(dist[v] == -1) {
                    dist[v] = dist[f] + 1;
                    q.push(v);
                }
            }
        }
        return reachableR;
    }

    bool dfs(int u) {
        for(auto&e : adj[u]) {
            auto v = matchR[e];
            if(v == -1 || (dist[v] == dist[u] + 1 && dfs(v))) {
                matchL[u] = e;
                matchR[e] = u;
                return true;
            }
        }
        dist[u] = -1;
        return false;
    }

    int max_matching() {
        int res = 0;
        while(bfs()) {
            for(int u = 0; u < nL; u++) {
                if(matchL[u] == -1 && dfs(u)) ++res;
            }
        }
        return res;
    }
};
