// Problem: Matrix Chain Multiplication
// Contest: ALDS1 - ALDS1_10_B
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=en
// Time Limit: 1000
// Start: 2024/08/28 14:25:54

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
    int n; cin >> n;
    vector<int> r(n), c(n);
    for(int i = 0; i < n; i++) cin >> r[i] >> c[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));

    for(int i = 0; i <= n; i++) dp[i][i] = 0;

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i+len-1 < n; i++) {
            int j = i+len-1;
            for(int k = i; k < j; k++) {
                ckmin(dp[i][j], dp[i][k] + dp[k+1][j] + r[i]*c[k]*c[j]);
            }
        }
    }

    cout << dp[0][n-1] << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

