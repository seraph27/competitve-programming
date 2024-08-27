// Problem: D - 1 年生 (A First Grader)
// Contest: 第１０回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d
// Time Limit: 10000
// Start: 2024/08/26 12:19:47

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
    int n; cin >> n;
    vector<int> vals(n-1);
    for(auto&a: vals) cin >> a;
    int last; cin >> last;

    debug(vals);
    vector<ll> dp(25, 0);
    dp[vals[0]] = 1;

    for(int i = 1; i < n-1; i++) {
        vector<ll> dp2(25, 0);
        for(int j = 0; j <= 20; j++) {
            if(j + vals[i] <= 20) {
                ckmax(dp2[j + vals[i]], dp[j] + dp2[j + vals[i]]);
            }
            if(j - vals[i] >= 0) {
                ckmax(dp2[j - vals[i]], dp[j] + dp2[j - vals[i]]);
            }
        }

        swap(dp, dp2);
    }
    debug(dp);

    cout << dp[last] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

