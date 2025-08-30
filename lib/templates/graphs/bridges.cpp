vector<pii> bridges(int n, const vector<vector<pii>> &adj) {
    vector<int> tin(n, -1), low(n, 0), vis(n, 0);
    int timer = 0;
    vector<pii> res;

    auto dfs = [&](auto &&s, int u, int pe) -> void {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for (auto &[v, id] : adj[u]) {
            if (id == pe) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                s(s, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) res.pb({u, v});
            }
        }
    };

    for (int i = 0; i < n; i++) if (!vis[i]) dfs(dfs, i, -1);
    return res;
}
