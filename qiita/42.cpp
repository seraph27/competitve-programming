// Problem: D - シルクロード (Silk Road)
// Contest: 第１４回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d
// Time Limit: 10000
// Start: 2024/08/27 2:06:54

//minimal template
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
    int n, m; cin >> n >> m;
    vector<int> dist(n);
    for(auto&a : dist) cin >> a;
    
    vector<int> cost(m);
    for(auto&a : cost) cin >> a;


    int dp[n+5][m+5];
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            ckmin(dp[i+1][j+1], dp[i][j] + cost[j] * dist[i]);
            ckmin(dp[i][j+1], dp[i][j]);
        }
    }

    cout << dp[n][m] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

