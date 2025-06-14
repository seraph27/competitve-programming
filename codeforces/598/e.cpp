// Problem: E. Chocolate Bar
// Contest: Educational Codeforces Round 1
// URL: https://codeforces.com/contest/598/problem/E
// Time Limit: 2000
// Start: Tue Jun 10 01:44:36 2025
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
int dp[31][31][51]{}; //
void shiina_mashiro() {
    memset(dp, 0x3f, sizeof dp);
    dp[1][1][1] = 0;

    for(int i = 1; i < 31; i++) {
        for(int j = 1; j < 31; j++) {
            for(int k = 0; k <= i*j; k++) {
                for(int row = 1; row < 31; row++) { //try adding back some row
                    int add = j * row;
                    if(k+add<=50 && i + row <= 30) ckmin(dp[i+row][j][k+add], dp[i][j][k] + j * j);
                }
                for(int col = 1; col < 31; col++) {
                    int add = i * col;
                    if(k+add<=50 && j + col <= 30) ckmin(dp[i][j+col][k+add], dp[i][j][k] + i * i);
                }
            }
        }
    }
    debug(dp);

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int n, m, k; cin >> n >> m >> k;
        if(n * m == k) {
            cout << 0 << nl;
            continue;
        }

        cout << dp[n][m][k] << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

