// Problem: C - Students and Shoelaces
// Contest: UCSD ICPC SP25 Week 5
// URL: https://vjudge.net/contest/713119#problem/C
// Time Limit: 2000
// Start: 2025/04/28 18:52:25
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
    int n, m; cin >> n >> m;
    vector<set<int>> adj(n);
    vector<int> deg(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u;--v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    set<int> good;
    for(int i = 0; i < n; i++) good.insert(i);
    vector<int> vis(n, 0);
    vector<int> bad;
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        if(deg[u] == 1) bad.pb(u);
        for(auto&e : adj[u]) if(!vis[e]) {
            s(s, e);
        }
    };
    int ans = 0;
    while(true) {
        fill(all(vis), 0);
        bad.clear();
        if(good.empty()) break;
        for(auto u : good) if(!vis[u]) dfs(dfs, u);
        if(bad.empty()) break;
        debug(bad);
        vector<ar<int, 2>> del;
        for(auto x : bad) {
            if(deg[x] == 1) {
                del.pb({x, *adj[x].begin()});
            }
        }
        for(auto &[x, to] : del) {
            adj[x].clear();
            adj[to].erase(x);
            deg[x]--;
            deg[to]--;
            good.erase(x);
            if(deg[to]== 0) {
                good.erase(to);
            }
        }
        ans++;
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

