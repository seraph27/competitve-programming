// Problem: C - トーナメント
// Contest: Typical DP Contest
// URL: https://atcoder.jp/contests/tdpc/tasks/tdpc_tournament
// Time Limit: 2000
// Start: Sat Jun 28 22:38:50 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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


double dp[1 << 10][11]{}; //probability that person i gets to round i;
void shiina_mashiro() {
    int k; cin >> k;
    vector<int> rating(1<<k, 0);
    for(int i = 0; i < (1<<k); i++) cin >> rating[i];

    auto f = [&](int a, int b) -> double {
        double top = (double)(a - b) / 400.0;
        return 1 / (1 + pow(10, top));
    };
    for(int i = 0; i < (1 << k); i++) {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < (1 << k); j++) dp[j][i] = 0;
        for(int j = 0; j < (1 << k); j++) {
            for(int nj = 0; nj < (1 << k); nj++) {
                if((j >> i) != (nj >> i)) continue;
                if((j >> (i-1)) == (nj >> (i-1))) continue;
                auto winprob = f(rating[nj], rating[j]);
                dp[j][i] += dp[nj][i - 1] * winprob * dp[j][i - 1];
            }
        }
    }
    for(int i = 0; i < (1 << k); i++) {
        cout << fixed << setprecision(10) << dp[i][k] << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

