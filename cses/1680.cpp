// Problem: Longest Flight Route
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1680
// Time Limit: 1000
// Start: Mon Jun 30 17:21:24 2025
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

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<pii> edges;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        edges.pb({a, b});
    }
    sort_unique(edges);
    for(auto &[a, b] : edges) adj[a].pb(b);
    vector<int> topo;
    vector<int> vis(n, 0);
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        for(auto&e: adj[u]) if(!vis[e]) {
            s(s, e);
        }
        topo.pb(u);
    };

    dfs(dfs, 0);
    reverse(all(topo));
    debug(topo);
    vector<int> par(n, -1);
    vector<int> dist(n, -1);
    dist[0] = 0;
    for(int i = 0; i < sz(topo); i++) {
        for(auto &e : adj[topo[i]]) {
            if(ckmax(dist[e], dist[topo[i]] + 1)) {
                par[e] = topo[i];
            }
        }
    }
    if(dist[n-1] == -1) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    cout << dist[n-1] + 1 << nl;
    vector<int> path;
    for(auto x = n-1; x != -1; x = par[x]) {
        path.pb(x);
    }
    reverse(all(path));
    for(int i = 0; i < sz(path); i++) cout << path[i]+1 << " ";
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

