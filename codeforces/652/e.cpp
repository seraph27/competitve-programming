// Problem: E. Pursuit For Artifacts
// Contest: Educational Codeforces Round 10
// URL: https://codeforces.com/problemset/problem/652/E
// Time Limit: 3000
// Start: Sat Aug 23 04:49:22 2025
// mintemplate
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
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x; --y;
        adj[x].pb({y, z});
        adj[y].pb({x, z});
    }

    vector<int> dep(n, 0), par(n, -1), dp(n, 0);
    set<pii> bridges;

    auto dfs = [&](auto&&s, int u, int p) -> void {
        for(auto&[e, w] : adj[u]) if(e != p) {
            if(!dep[e]) {
                dep[e] = dep[u] + 1;
                par[e] = u;
                s(s, e, u);
                dp[u] += dp[e];
            } else if(dep[e] < dep[u]) {
                dp[u]++;
            } else if(dep[e] > dep[u]) {
                dp[u]--;
            }
        }
        if(par[u] != -1 && dp[u] == 0) {
            bridges.insert({u, par[u]});
            bridges.insert({par[u], u});
        }
    };
    dfs(dfs, 0, -1);

    DSU uf(n);
    set<pii> on_edge;
    for(int u = 0; u < n; u++) {
        for(auto&[e, w] : adj[u]) if(u < e) {
            if(!bridges.count({u, e})) {
                uf.merge(u, e);
            }
        }
    }

    vector<int> has_artifact(n, 0);
    vector<vector<int>> adj2(n);
    for(int u = 0; u < n; u++) for(auto&[e, w] : adj[u]) {
        if(bridges.count({u, e})) {
            if(w) on_edge.insert({uf.find(u), uf.find(e)});
        } else {
            if(w) has_artifact[uf.find(u)] = 1;
        }
        int c1 = uf.find(u), c2 = uf.find(e);
        if(c1 == c2) continue;
        adj2[c1].pb(c2);
    }
    debug(adj2, has_artifact, on_edge);
    int a, b; cin >> a >> b;
    --a; --b;
    vector<int> par2(n, -1);
    auto dfs2 = [&](auto&&s, int u, int p) -> void {
        for(auto&e : adj2[u]) if(e != p) {
            par2[e] = u;
            s(s, e, u);
        }
    };
    dfs2(dfs2, uf.find(a), -1);
    
    bool ok = 0;
    for(auto v = uf.find(b); v != -1; v = par2[v]) {
        if(has_artifact[v] || on_edge.count({v, par2[v]})) ok = 1;
    }

    cout << (ok ? "YES" : "NO") << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

