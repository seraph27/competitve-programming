// Problem: E. Three Strings
// Contest: Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/contest/2050/problem/E
// Time Limit: 2500
// Start: Thu Dec  5 07:25:32 2024
// mintemplate
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

void shiina_mashiro() {
    string a, b; cin >> a >> b;
    string c; cin >> c;
    int n = sz(a), m = sz(b), o = sz(c);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 4e18));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        if(i-1 < o)dp[i][0] = dp[i-1][0] + (a[i-1] != c[i-1] ? 1 : 0);

    }
    for(int j = 1; j <= m; ++j){
        if(j-1 < o) dp[0][j] = dp[0][j-1] + (b[j-1] != c[j-1] ? 1 : 0);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int pos = i + j -1;
            if(pos >= o){
                continue;
            }
            if(dp[i-1][j] != 4e18){
                int cost = dp[i-1][j] + (a[i-1] != c[pos] ? 1 : 0);
                ckmin(dp[i][j], cost);
            }
            if(dp[i][j-1] != 4e18){
                int cost = dp[i][j-1] + (b[j-1] != c[pos] ? 1 : 0);
                ckmin(dp[i][j], cost);
            }
        }
    }
    cout << dp[n][m] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

