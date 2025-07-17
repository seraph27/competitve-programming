// Problem: Coin Collector
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1686
// Time Limit: 1000
// Start: Wed Jul 16 13:29:03 2025
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
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> adj(n), radj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    vector<int> topo, vis(n, 0);
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        for(auto&e: adj[u]) if(!vis[e]) s(s, e);
        topo.pb(u);
    };

    for(int i = 0; i < n; i++) if(!vis[i]) dfs(dfs, i);

    vector<int> who(n, -1);
    int comps = 0;

    auto dfs2 = [&](auto&&s, int u) -> void {
        who[u] = comps;
        for(auto &e : radj[u]) if(who[e] == -1) s(s, e);
    };

    for(int i = n-1; i>=0; i--) {
        int u = topo[i];
        if(who[u] == -1) {
            dfs2(dfs2, u);
            comps++;
        }
    }

    vector<int> C(comps, 0);
    for(int i = 0; i < n; i++) {
        C[who[i]] += coins[i];
    }

    vector<vector<int>> nadj(comps);
    vector<int> indeg(comps);
    for(int i = 0; i < n; i++) for(auto&e: adj[i]) {
        if(who[e] != who[i]) {
            nadj[who[i]].pb(who[e]);
            indeg[who[e]]++;
        }
    }

    queue<int> q;
    vector<int> dp(comps);
    for(int i = 0; i < comps; i++) {
        if(!indeg[i]) {
            dp[i] = C[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto f = q.front(); q.pop();
        for(auto&e : nadj[f]) {
            ckmax(dp[e], dp[f] + C[e]);
            if(--indeg[e] == 0) {
                q.push(e);
            }
        }
    }
    cout << *max_element(all(dp)) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

