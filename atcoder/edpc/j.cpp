// Problem: J - Sushi
// Contest: Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_j
// Time Limit: 2000
// Start: Sun May  3 16:10:54 2026
// atcoder
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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

using mint = modint998244353;
const char nl = '\n';

void shiina_mashiro() {
    //maybe have dp[i][j][k] := ith 1 plat, jth 2 plate, kth 3 plate? 
    

    int n; cin >> n;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x == 1) a++;
        else if(x == 2) b++;
        else c++;
    }
    
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, 0)));
    
    auto f = [&](this auto && s, db a, db b, db c) -> double {
        if(dp[a][b][c]) return dp[a][b][c];
        if(a == 0 && b == 0 && c == 0) return 0;
        double sum = a + b + c;
        dp[a][b][c] = n / sum;
        if(c > 0) dp[a][b][c] += s(a, b + 1, c - 1) * (c / sum);
        if(b > 0) dp[a][b][c] += s(a + 1, b - 1, c) * (b / sum);
        if(a > 0) dp[a][b][c] += s(a - 1, b, c) * (a / sum);

        return dp[a][b][c];
    };

    f(a, b, c);
    cout << fixed << setprecision(20) << dp[a][b][c] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
