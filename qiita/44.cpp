// Problem: Pollock's conjecture
// Contest: Volume11 - 1167
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp
// Time Limit: 8000
// Start: 2024/08/27 16:15:35

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
    vector<int> init;
    const int MX = 1e6+5;
    for(int i = 1; ; i++) {
        int cnt = i*(i+1)*(i+2)/6;
        if(cnt >= MX) break;
        init.pb(cnt);
    }

    vector<int> dp(MX, INF), dp2(MX, INF);
    dp[0] = 0;
    dp2[0] = 0;

    for(int i = 0; i < MX; i++) {
        for(int j = 0; j < sz(init); j++) {
            if(i + init[j] < MX) {
                ckmin(dp[i + init[j]], dp[i] + 1);
            }
            if(init[j]%2 && i + init[j] < MX) {
                ckmin(dp2[i + init[j]], dp2[i] + 1);
            }
        }
    }

    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        cout << dp[n] << " " << dp2[n] << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

