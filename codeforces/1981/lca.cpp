// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    //n nodes, n-1 edges, given q queries, find lca(x, y);
    
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int uu, vv; cin >> uu >> vv;
        adj[uu].pb(vv);
        adj[vv].pb(uu);
    }

    vector<int> dep(n+1, 0);
    vector up(n+1, vector<int>(31, 0)); //up[i][j] := 2^j th ancestor of node i;

    auto dfs = [&](auto&&s, int u, int p) -> void { 
        up[u][0] = p;
        dep[u] = dep[p] + 1;
        for(int j = 1; j < 31; j++) {
            up[u][j] = up[up[u][j-1]][j-1]; //up[7][0] = 6 up[7][1] = up[6][0] = 5, up[7][2] = up[5][1] = 3....
        }

        for(int j = 0; j < sz(adj[u]); j++) {
            if(adj[u][j] != p) s(s, adj[u][j], u);
        }
    };

    
    dfs(dfs, 1, 0);
    debug(dep, up, adj);
    auto lca = [&](int x, int y) -> int {
        if(dep[x] > dep[y]) swap(x, y);
        int diff = dep[y] - dep[x];

        for(int j = 0; diff; diff>>=1, j++) {
            if(diff & 1) {
                y = up[y][j];
            }
        }
        if(x==y) return x;
        for(int j = 30; j>=0 && x != y; j--) {
            if(up[x][j] != up[y][j]) {
                x = up[x][j];
                y = up[y][j];
            }
        }
        return up[x][0];
    };
    
    int m; cin >> m;
    for(;m--;) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << nl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}


