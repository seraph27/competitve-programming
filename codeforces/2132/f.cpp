// Problem: F. Rada and the Chamomile Valley
// Contest: Codeforces Round 1043 (Div. 3)
// URL: https://codeforces.com/contest/2132/problem/F
// Time Limit: 3000
// Start: Fri Aug 22 06:44:38 2025
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

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    map<pii, int> mp;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
        mp[{u, v}] = i;
        mp[{v, u}] = i;
    }

    auto res = st_bridges(n, adj, 0, n-1);

    queue<int> q;
    
    vector<int> dist(n, 4e18), near(n, 4e18);
    for(auto&[a, b] : res) {
        int id = mp[{a, b}];
        ckmin(near[a], id), ckmin(near[b], id);
        dist[a] = 0;
        dist[b] = 0;
    }

    for(int u = 0; u < n; u++) if(dist[u] == 0 && near[u] != 4e18) q.push(u);

    while(!q.empty()) {
        auto f = q.front(); q.pop();
        for(auto &e : adj[f]) {
            if(dist[e] == 4e18){
                dist[e] = dist[f] + 1;
                near[e] = near[f];
                q.push(e);
            } else if(dist[e] == dist[f] + 1 && near[f] < near[e]) {
                near[e] = near[f];
                q.push(e);
            }
        }
    }
    debug(res, dist);
    int qq; cin >> qq;
    for(;qq--;) {
        int c; cin >> c;
        --c; 
        if(!sz(res) || near[c] == 4e18) {cout << -1 << " "; continue;}
        cout << near[c] + 1 << " ";
    }
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

