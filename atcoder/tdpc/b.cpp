// Problem: B - ゲーム
// Contest: Typical DP Contest
// URL: https://atcoder.jp/contests/tdpc/tasks/tdpc_game
// Time Limit: 2000
// Start: Sat Jun 28 22:00:48 2025
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
int dp[1002][1002]{};

void shiina_mashiro() {
    int a, b; cin >> a >> b;
    vector<int> va(a), vb(b);
    for(int i = 0; i < a; i++) cin >> va[i];
    for(int j = 0; j < b; j++) cin >> vb[j];
    
    reverse(all(va));
    reverse(all(vb));
    vector<int> prefA(a+1), prefB(b+1);
    
    for(int i = 0; i < a; i++) prefA[i+1] += prefA[i] + va[i];
    for(int i = 0; i < b; i++) prefB[i+1] += prefB[i] + vb[i];

    for(int i = 1; i <= a; i++) {
        dp[i][0] = prefA[i-1] + va[i-1] - dp[i-1][0];
    }
    for(int i = 1; i <= b; i++) {
        dp[0][i] = prefB[i-1] + vb[i-1] - dp[0][i-1];
    }
    for(int i = 1; i <= a; i++) for(int j = 1; j <= b; j++) {
        ckmax(dp[i][j], prefA[i-1] + prefB[j] + va[i-1] - dp[i-1][j]);
        ckmax(dp[i][j], prefA[i] + prefB[j-1] + vb[j-1] - dp[i][j-1]);
    }
    cout << dp[a][b] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

