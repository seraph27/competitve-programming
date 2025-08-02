vector<int> color(n, 0);
bool cycle = false;
auto dfs = [&](auto &&s, int u) -> void {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 0) s(s, v);
        else if (color[v] == 1) cycle = true;
    }
    color[u] = 2;
};
for (int i = 0; i < n; i++) if (color[i] == 0) dfs(dfs, i);