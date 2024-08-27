// Problem: D - 暑い日々 (Hot days)
// Contest: 第１２回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d
// Time Limit: 10000
// Start: 2024/08/26 21:00:46

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
    int d, n; cin >> d >> n;
    vector<int> temp(d);
    for(auto&a: temp) cin >> a;

    vector<int> mntemp(n), mxtemp(n), hade(n);
    for(int i = 0; i < n; i++) cin >> mntemp[i] >> mxtemp[i] >> hade[i];

    vector<int> dp(105, -INF); // last hade value -> maximum hade
    
    for(int i = 0; i < d; i++) {
        vector<int> dp2(105, -INF);
        if(i == 0) {
            for(int j = 0; j < n; j++) {
                if(mntemp[j]<=temp[i] && mxtemp[j]>=temp[i]) {
                    ckmax(dp2[hade[j]], 0);
                }
            }
        } else {
            for(int j = 0; j < n; j++) { //new pick
                for(int k = 0; k < n; k++) {  //last pick
                    if(mntemp[j]<=temp[i] && mxtemp[j]>=temp[i]) {
                        ckmax(dp2[hade[j]], dp[hade[k]] + abs(hade[j] - hade[k]));
                    }
                }
            }
        }
        swap(dp, dp2);
    }
    int ans = 0;
    for(int i = 0; i < sz(dp); i++) {
        ckmax(ans, dp[i]);
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

