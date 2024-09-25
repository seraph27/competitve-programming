// Problem: F. Sheriff's Defense
// Contest: Codeforces Round 974 (Div. 3)
// URL: https://codeforces.com/contest/2014/problem/F
// Time Limit: 2000
// Start: 2024/09/22 19:59:14

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
    int n, c; cin >> n >> c;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector dp(n+5, vector<ll>(2, 0));
    auto dfs = [&](auto&&s, int u, int p) -> void {
        dp[u][1] = vi[u-1];
        for(auto &e : adj[u]) if(e != p) {
            s(s, e, u);
            dp[u][0]+=max(dp[e][0], dp[e][1]);
            dp[u][1]+=max(dp[e][0], dp[e][1]-2*c);
        }
    }; 
    dfs(dfs, 1, -1);
    cout << max(dp[1][0], dp[1][1]) << nl;
     
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
