// Problem: C. New Rating
// Contest: Refact.ai Match 1 (Codeforces Round 985)
// URL: https://codeforces.com/contest/2029/problem/C
// Time Limit: 2000
// Start: Sat Nov  9 06:36:25 2024
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
template<typename T> bool ckmin(T &a, const T &b) { return a >= b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a <= b ? a = b, 1 : 0; }
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
    int n; cin >> n;
    vector<int>vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    
    auto chk = [&](int a, int b) {
        if(a==b) return 0;
        return a > b ? 1 : -1;
    };
    int INF = 1e9;
    ar<int, 3> dp = {0, -INF, -INF}; 
    for(int i = 0; i < n; i++) {
        ar<int, 3> dp2 = {0, -INF, -INF};
        ckmax(dp2[0], dp[0] + chk(vi[i], dp[0]));
        ckmax(dp2[1], dp[0]);
        ckmax(dp2[1], dp[1]);
        ckmax(dp2[2], dp[1]);
        ckmax(dp2[2], dp[2] + chk(vi[i], dp[2]));
        ckmax(dp2[2], dp[1] + chk(vi[i], dp[2]));
        swap(dp, dp2);
    }
    int ans = max(dp[1], dp[2]);
    if(ans==n) ans--;
    cout << ans << nl;
    
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
