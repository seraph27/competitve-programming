// Problem: F. Timofey and Black-White Tree
// Contest: Codeforces Round 847 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1790/F
// Time Limit: 4000
// Start: 2025/05/05 18:29:47
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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

void shiina_mashiro() {
    int n, init; cin >> n >> init;
    --init;
    vector<vector<int>> adj(n);
    vector<int> ops(n-1);
    for(auto&a: ops) {
        cin >> a;
        --a;
    }
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vector<int> dist(n, 1e9);
    queue<int> q;
    dist[init] = 0;
    q.push(init);
    while(!q.empty()) {
        auto u = q.front(); q.pop();
        for(auto e : adj[u]) {
            if(ckmin(dist[e], dist[u] + 1)) {
                q.push(e);
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i < n-1; i++) {
        debug(dist);
        int x = ops[i];
        dist[x] = 0;
        auto dfs = [&](auto&&s, int u, int p) -> void {
            if(dist[u] > ans) return; //very important lol you have to immediately stop the dfs if dist[u] already > ans, it means there's no use going down
            for(auto&e: adj[u]) if(e != p) {
                if(ckmin(dist[e], dist[u] + 1)) {
                    s(s, e, u);
                } else {
                    ckmin(ans, dist[e] + dist[u] + 1);
                }
            }
        };
        dfs(dfs, x, -1);
        cout << ans << " ";
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

