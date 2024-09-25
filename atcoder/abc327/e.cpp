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
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    reverse(all(vi));
    vector<double> exp(n+5), add(n+5), sqr(n+5);
    exp[0] = 1;
    add[0] = 1;
    sqr[0] = 1;
    for(int i = 0; i <= n; i++) {
        exp[i+1] = exp[i]*0.9;
        add[i+1] = add[i] + exp[i+1];
        if(i>0) sqr[i] = sqrt(i);
    }
    debug(exp, add, sqr);
    vector<pair<double, int>> dp1(n+5, {-INF, 0});
    dp1[0] = {0, 0};
    for(int i = 0; i < n; i++) {
        vector<pair<double, int>> dp2(n+5, {-INF, 0});
        for(int j = 0; j < i; j++) {
            ckmax(dp2[j], dp1[j]);
            double pick = dp1[j].first + 1200/sqr[dp1[j].second];
            pick*=add[dp1[j].second];
            pick+=exp[dp1[j].second+1]*vi[j];
            pick/=add[dp1[j].second+1];
            pick-=1200/sqr[dp1[j].second+1];
            debug(pick);
            pair<double, int> ad = {pick, dp1[j].second+1};
            ckmax(dp2[j], ad);
        }
        debug(dp1, dp2);
        swap(dp1, dp2);
    }
    cout << dp1[n].first << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
