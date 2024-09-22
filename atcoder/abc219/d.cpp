// Problem: D - Strange Lunchbox
// Contest: サイシードプログラミングコンテスト2021（AtCoder Beginner Contest 219）
// URL: https://atcoder.jp/contests/abc219/tasks/abc219_d
// Time Limit: 2000
// Start: 2024/09/12 15:50:19

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
    int n, x, y; cin >> n >> x >> y;
    vector<ar<int, 2>> lunch(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        lunch[i] = {a, b};
    }

    vector dp(350, vector<int>(350, INF));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        vector ndp(350, vector<int>(350, INF));
        ndp[0][0] = 0;
        for(int j = 0; j <= 305; j++) for(int k = 0; k <= 305; k++){
            auto &[aa, bb] = lunch[i];
            ckmin(ndp[min(305, j+aa)][min(305, k+bb)], dp[j][k] + 1);
            ckmin(ndp[j][k], dp[j][k]);
        }
        swap(dp, ndp);
    }

    int ans = INF;
    for(int i = x; i <= 305; i++) for(int j = y; j <= 305; j++) {
        ckmin(ans, dp[i][j]);
    }
    cout << (ans==INF ? -1 : ans) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

