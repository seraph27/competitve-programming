// Problem: B - ケーキの切り分け２ (Cake 2)
// Contest: 第１４回日本情報オリンピック 本選（過去問）
// URL: https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b
// Time Limit: 2000
// Start: 2024/08/28 15:24:39

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
    vector<ll> piece(2*n, 0);
    vector<vector<ll>> dp(2*n, vector<ll>(2*n, 0)); //dp[i][j]:=max piece by eating from [i, j]
    for(int i = 0; i < n; i++) {
        cin >> piece[i];
        piece[i+n] = piece[i];
    }

    ll ans = 0;
    for(int len = 1; len <= n; len++) {
        for(int l = 0; l + len < 2*n; l++) {
            int r = l+len-1;
            if(l==r) {
                dp[l][r] = piece[l];
            } else if(len%2==0) { //IOI 5-2-1 = 2
                if(l!=0 && (piece[l-1] < piece[r])) ckmax(dp[l][r], dp[l][r-1]);
                if(piece[l] > piece[r+1]) ckmax(dp[l][r], dp[l+1][r]);
            } else { //JOI
                ckmax(dp[l][r], max(piece[l] + dp[l+1][r], piece[r] + dp[l][r-1]));
            }
            ckmax(ans, dp[l][r]);
        }
    }
    debug(dp);
    
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

