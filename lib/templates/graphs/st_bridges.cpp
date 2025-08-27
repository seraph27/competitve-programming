vector<pii> st_bridges(int n, const vector<vector<int>> &adj, int s, int t) {
    vector<int> tin(n, -1), low(n, 0), vis(n, 0);
    vector<int> hasT(n, 0);
    int timer = 0;
    vector<pii> res;

    auto dfs = [&](auto &&self, int u, int p) -> void {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        hasT[u] = (u == t);
        for (int v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u] && hasT[v]) res.pb({u, v}); 
                hasT[u] = hasT[u] | hasT[v];
            }
        }
    };

    if (!vis[s]) dfs(dfs, s, -1);
    return res;
}
