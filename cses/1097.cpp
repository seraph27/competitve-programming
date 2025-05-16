// Problem: Removal Game
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1097
// Time Limit: 1000
// Start: Wed May 14 23:35:10 2025
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
int dp[5005][5005];
void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    memset(dp, 0xc0, sizeof dp);
    vector<int> pref(n+1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + vi[i-1];
    }
    auto get = [&](int l, int r) {
        return pref[r+1] - pref[l];
    };
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            int R = i+len-1;
            if(i==R) {
                dp[i][R] = vi[i];
            } else {
                ckmax(dp[i][R], max(vi[i] + get(i+1, R) - dp[i+1][R], vi[R] + get(i, R-1) - dp[i][R-1]));
            }
        }
    }
    cout << dp[0][n-1] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

