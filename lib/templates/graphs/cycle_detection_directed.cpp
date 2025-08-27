vector<int> color(n, 0), par(n, -1), cyc;
bool cycle = false;
int cu = -1, cv = -1;
auto dfs = [&](auto &&s, int u) -> void {
    color[u] = 1;
    for (int v : adj[u]) {
        if (cycle) return;
        if (color[v] == 0) { par[v] = u; s(s, v); }
        else if (color[v] == 1) { cycle = true; cu = u; cv = v; return; }
    }
    color[u] = 2;
};
for (int i = 0; i < n && !cycle; i++) if (color[i] == 0) dfs(dfs, i);
if (cycle) {
    int x = cu;
    cyc.pb(cv);
    while (x != cv) { cyc.pb(x); x = par[x]; }
    reverse(all(cyc));
}
