// Problem: 吃奶酪
// Contest: %E6%B4%9B%E8%B0%B7
// URL: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1433
// Time Limit: 1000
// Start: Mon Aug 25 11:53:30 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define db double
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
    int n; cin >> n;
    vector<double> vx(n), vy(n);
    for(int i = 0; i < n; i++) {
        cin >> vx[i] >> vy[i];
    }

    double best_length = 4e18;
    auto f = [&](db x1, db y1, db x2, db y2) -> db { db dx = x2 - x1; db dy = y2 - y1; return sqrt(dx * dx + dy * dy); };
    double len[20][20];
    memset(len, 0, sizeof len);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j) {
        len[i][j] = f(vx[i], vy[i], vx[j], vy[j]);
    }


    
    vector<vector<double>> dp(1 << n, vector<double>(n, 4e18));
    for(int i = 0; i < n; i++) {
        ckmin(dp[1 << i][i], f(0, 0, vx[i], vy[i]));
    }
    for(int msk = 0; msk < (1 << n); msk++) {
        for(int k = 0; k < n; k++) if(msk >> k & 1) for(int j = 0; j < n; j++) {
            if(!((msk >> j) & 1)) {
                int nmsk = msk | (1 << j);
                ckmin(dp[nmsk][j], dp[msk][k] + len[j][k]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        ckmin(best_length, dp[(1 << n) - 1][i]);
    }

    cout << setprecision(2) << fixed << best_length << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

