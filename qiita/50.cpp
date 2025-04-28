// Problem: G - Revenge of Traveling Salesman Problem
// Contest: square869120Contest #1
// URL: https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
// Time Limit: 5000
// Start: 2025/04/24 11:07:31
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
#define fi first
#define se second
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

const int N = 17;
pair<int, int> dp[N][1 << N];
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<ar<int, 3>>> adj(n);

    if(n==1) {
        cout << "0 1" << nl;
        return;
    }
    for(int i = 0; i < m; i++) {
        int u, v, d, t; cin >> u >> v >> d >> t;
        u--, v--;
        adj[u].pb({v, d, t});
        adj[v].pb({u, d, t});
    }
    const int INF = 2e18;
    for(int i = 0; i < n; i++) for(int j = 0; j < (1 << n); j++) dp[i][j] = {INF, 0};
    dp[0][1].fi = 0;
    dp[0][1].se = 1;
    for(int msk = 0; msk < (1 << n); msk++) {
        for(int i = 0; i < n; i++) {
            if(dp[i][msk].fi == INF) continue;
            for(auto [j, d, t] : adj[i]) {
                if(msk & (1 << j)) continue;
                if(dp[i][msk].fi + d > t) continue;
                int best = dp[i][msk].fi + d;
                if(best < dp[j][msk | (1 << j)].fi) {
                    dp[j][msk | (1 << j)] = {best, dp[i][msk].se};
                } else if(best == dp[j][msk | (1 << j)].fi) {
                    dp[j][msk | (1 << j)].se += dp[i][msk].se;
                }
            }
        }
    }
    int ans = 4e18, paths = 0;
    for(int v = 0; v < n; v++) {
        auto full = dp[v][(1 << n) - 1];
        if(full.fi == INF) continue;
        for(auto [j, d, t] : adj[v]) {
            if(j!=0) continue;
            int tot = full.fi + d;
            if(tot > t) continue;
            if(tot < ans) {
                ans = tot;
                paths = full.se;
            } else if(tot == ans) {
                paths += full.se;
            }
        }
    }
    if(ans==4e18) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    cout << ans << " " << paths << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

