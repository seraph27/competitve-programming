// Problem: F. Small Operations
// Contest: Codeforces Round  1027 (Div. 3)
// URL: https://codeforces.com/contest/2114/problem/F
// Time Limit: 3000
// Start: 2025/05/27 22:18:55
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
    int x, y, k; cin >> x >> y >> k;
    int gd = gcd(x, y);
    int sx = x / gd, sy = y / gd;
    int ans = 0;

    auto slv = [&](int v) {
        vector<int> dp(v+1, 1e18);
        dp[1] = 0;
        vector<int> divs;
        for(int i = 1; i*i <= v; i++) {
            if(v%i==0) {
                divs.pb(i);
                if(i*i != v) divs.pb(v/i);
            }
        }
        sort(all(divs));
        for(int i : divs) {
            for(auto j : divs) {
                if(j <= k && i*j <= v) ckmin(dp[i * j], dp[i] + 1);
                else break;
            }
        }
        return dp[v];
    };

    auto sum = slv(sx) + slv(sy);
    cout << (sum >= 32 ? -1 : sum) << nl;



    
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

