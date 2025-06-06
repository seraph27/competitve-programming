// Problem: Longest Common Subsequence
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/3403
// Time Limit: 1000
// Start: 2025/05/14 13:09:13
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

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(auto &a: v1) cin >> a;
    for(auto &b: v2) cin >> b;

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    vector<vector<int>> path(n+1, vector<int> (m+1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v1[i] == v2[j]) {
                if(ckmax(dp[i+1][j+1], dp[i][j] + 1)) {
                    path[i+1][j+1] = 1;
                }
            }
            ckmax(dp[i+1][j+1], max(dp[i][j+1], dp[i+1][j]));
        }
    }
    cout << dp[n][m] << nl;
    vector<int> ans;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(path[i][j] == 1) {
            ans.pb(v1[i-1]);
            i--;
            j--;
        } else if(dp[i][j] == dp[i-1][j]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(all(ans));
    for(auto a: ans) cout << a << " ";
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

