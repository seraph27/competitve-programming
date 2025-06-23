// Problem: E. Sponsor of Your Problems
// Contest: Codeforces Round 1032 (Div. 3)
// URL: https://codeforces.com/contest/2121/problem/E
// Time Limit: 2000
// Start: 2025/06/17 22:51:18
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

void shiina_mashiro() {
    int l, r; cin >> l >> r;

    int dp[10][2][2]{};
    memset(dp, 0x3f, sizeof dp);
    dp[0][1][1] = 0;

    vector<int> A, B;
    for(auto x = l; x > 0; x /= 10) A.pb(x % 10);
    for(auto x = r; x > 0; x /= 10) B.pb(x % 10);
    reverse(all(A));
    reverse(all(B));
    int n = sz(A);
    debug(A, B);

    for(int i = 0; i < n; i++) {
        for(int t = 0; t < 2; t++) for(int s = 0; s < 2; s++) {
            for(int d = (t ? A[i] : 0); d <= (s ? B[i] : 9); d++) {
                bool nt = t && (d == A[i]);
                bool ns = s && (d == B[i]);
                int add = (d == A[i]) +  (d == B[i]);
                ckmin(dp[i+1][nt][ns], dp[i][t][s] + add);
            }
        }
    }
    int ans = 1e8;
    for(int t = 0; t < 2; t++) for(int s = 0; s < 2; s++) {
        ckmin(ans, dp[n][t][s]);
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

