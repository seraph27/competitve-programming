// Problem: D - パスタ (Pasta)
// Contest: 第１１回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d
// Time Limit: 10000
// Start: 2024/08/26 13:31:24

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
const int mod = 10000;

void shiina_mashiro() {
    int n, g; cin >> n >> g;
    int dp[n+5][3][2]; //idx, last pick, are the last two picks same?
    memset(dp, 0, sizeof(dp));

    vector<int> choice(n, -1);
    for(int i = 0; i < g; i++) {
        int d, c; cin >> d >> c;
        --d; --c;
        choice[d] = c;
    }
    
    debug(choice);
    if(choice[0] == -1) {
        for(int i = 0; i < 3; i++) {
            dp[1][i][0] = 1; 
        }
    } else {
        dp[1][choice[0]][0] = 1;
    }

    for(int i = 1; i < n; ++i) {
        if(choice[i] == -1) { 
            for(int j = 0; j < 3; j++) { //new pick
                for(int k = 0; k < 3; k++) { //prev pick
                    if(k == j) {
                        dp[i+1][j][1] += dp[i][k][0] % mod;
                    } else {
                        dp[i+1][j][0] += (dp[i][k][0] + dp[i][k][1]) % mod;
                    }
                }
            }
        } else {
            for(int k = 0; k < 3; k++) { //prev pick, but can't pick anything
                if(k == choice[i]) {
                    dp[i+1][choice[i]][1] += dp[i][k][0] % mod;
                } else {
                    dp[i+1][choice[i]][0] += (dp[i][k][0] + dp[i][k][1]) % mod;
                }
            }
        }
        debug(dp[i][0][0], dp[i][1][0], dp[i][2][0], i);
    }
    ll ans = 0;
    for(int i = 0; i < 2; i++) for(int j = 0; j < 3; j++) {
        ans+=dp[n][j][i];
        ans%=mod;
    }

    cout << ans << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

