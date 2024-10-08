// Problem: E - Maximize Rating
// Contest: HHKBプログラミングコンテスト2023(AtCoder Beginner Contest 327)
// URL: https://atcoder.jp/contests/abc327/tasks/abc327_e
// Time Limit: 2000
// Start: 2024/08/18 1:24:03

#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n+1);
    for(int i = 1; i <= n; i++) cin >> vi[i];
    vector<double> sqr(n+5), exp(n+5, 0);
    double c = 1;
    for(int i = 1; i <= n; i++) {
        exp[i] += exp[i-1];
        exp[i] += c;
        c*=0.9;
        sqr[i] = sqrt(i); 
    }
    debug(exp, sqr);
    //dp[i][j]:= maximum rating picking up until ith idx picking j different contests;

    vector<vector<double>> dp(n+5, vector<double>(n+5, 0));
    dp[1][1] = vi[1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j==1) {
                ckmax(dp[i][j], max(dp[i-1][1], (double)vi[i]));
            } else {
                ckmax(dp[i][j], max(dp[i-1][j-1]*0.9 + vi[i], dp[i-1][j]));
            }
        }
    }
    double ans = -1200;
    for(int j = 1; j <= n; j++) {
        double res = dp[n][j] / exp[j] - 1200 / sqr[j]; 
        ckmax(ans, res);
    }
    cout << fixed << setprecision(20) << ans << nl;


}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
