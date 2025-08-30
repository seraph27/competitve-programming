vector<int> color(n), vis(n);
auto dfs = [&](auto&&ss, int u) -> bool {
    vis[u] = 1;
    bool ok = true;
    for(auto&e : adj[u]) {
        if(!vis[e]) {
            color[e] = (color[u] == 1 ? 2 : 1);
            ok = ss(ss, e) && ok;
        } else {
            if(color[e] == color[u]) ok = false;
        }
    }
    return ok;
};
