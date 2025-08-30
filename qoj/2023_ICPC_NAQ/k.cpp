#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif

const char nl = '\n';

struct DSU {
    vector<int> f, siz;
    DSU(int n) { init(n); }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        siz[x] += siz[y]; f[y] = x;
        return true;
    }
};

struct LCA {
    int n, LOG, root;
    const vector<vector<pii>> &adj;
    vector<int> depth, par, pedge;
    vector<vector<int>> up;
    vector<vector<int>> min_replace;
    const int INF = 4e18;

    LCA(const vector<vector<pii>> &adj, int root = 0) : n(sz(adj)), LOG(0), root(root), adj(adj) {
        while ((1 << LOG) <= n) ++LOG;
        depth.assign(n, 0);
        par.assign(n, root);
        pedge.assign(n, 0);
        up.assign(n, vector<int>(LOG, root));
        min_replace.assign(n, vector<int>(LOG, INF));
        
        vector<int> q; q.push_back(root);
        vector<bool> vis(n, false); vis[root] = true;
        int head = 0;
        while(head < sz(q)) {
            int u = q[head++];
            for(auto& [v, w] : adj[u]) {
                if(!vis[v]) {
                    vis[v] = true;
                    depth[v] = depth[u] + 1;
                    par[v] = u;
                    pedge[v] = w; 
                    q.push_back(v);
                }
            }
        }

        for (int i = 0; i < n; ++i) up[i][0] = par[i];
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
    
    int get_lca_node(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for(int j = LOG - 1; j >= 0; j--) {
            if(depth[u] - (1 << j) >= depth[v]) {
                u = up[u][j];
            }
        }
        if (u == v) return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) { 
                u = up[u][j]; v = up[v][j]; 
            }
        }
        return par[u];
    }
    
    void update_path(int u, int v, int w) {
        int l = get_lca_node(u, v);
        for(int j = LOG - 1; j >= 0; j--) {
            if(depth[u] - (1 << j) >= depth[l]) {
                ckmin(min_replace[u][j], w);
                u = up[u][j];
            }
        }
        for(int j = LOG - 1; j >= 0; j--) {
            if(depth[v] - (1 << j) >= depth[l]) {
                ckmin(min_replace[v][j], w);
                v = up[v][j];
            }
        }
    }
    
    void propagate() {
        for (int j = LOG - 1; j >= 1; j--) {
            for (int i = 0; i < n; i++) {
                ckmin(min_replace[i][j - 1], min_replace[i][j]);
                ckmin(min_replace[up[i][j - 1]][j - 1], min_replace[i][j]);
            }
        }
    }
};

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<ar<int, 4>> edges(m);
    vector<ar<int, 3>> initial_edges(m);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        edges[i] = {w, a, b, i};
        initial_edges[i] = {a, b, w};
    }

    sort(all(edges));
    DSU uf(n);
    int cost = 0;
    vector<int> used(m, 0);
    for(auto &e : edges) {
        if(uf.merge(e[1], e[2])) {
            cost += e[0];
            used[e[3]] = 1;
        }
    }

    vector<vector<pii>> tree(n);
    for (int i = 0; i < m; ++i) if (used[i]) {
        auto& e = initial_edges[i];
        tree[e[0]].pb({e[1], e[2]});
        tree[e[1]].pb({e[0], e[2]});
    }
    
    LCA lc(tree);

    for (int i = 0; i < m; ++i) if(!used[i]) {
        auto& e = initial_edges[i];
        lc.update_path(e[0], e[1], e[2]);
    }
    
    lc.propagate();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == lc.root) continue;
        int replacement_w = lc.min_replace[i][0];
        if (replacement_w != lc.INF) {
            int edge_to_parent_w = lc.pedge[i];
            ckmax(ans, cost - edge_to_parent_w + replacement_w);
        }
    }
    
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) shiina_mashiro();
}
