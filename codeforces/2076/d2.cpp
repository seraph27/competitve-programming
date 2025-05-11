// Problem: D. Equalization
// Contest: Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2075/problem/D
// Time Limit: 3500
// Start: Wed May  7 01:29:57 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
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

int dp[61][61];

void pre() {
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int k = 1; k <= 59; k++) {
        int cost = 1LL<<k;
        for(int i = 59; i >= 0; i--) {
            for(int j = 59; j >= 0; j--) {
                if (i >= k) dp[i][j] = min(dp[i][j], dp[i-k][j] + cost);
                if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j-k] + cost);
            }
        }
    }
}
void shiina_mashiro() {
    int x, y; cin >> x >> y;
    if(x==y) {
        cout << 0 << nl;
        return;
    }
    if(x > y) swap(x, y);
    int tpx = -1, tpy = -1;
    if(x) tpx = 63 - __builtin_clzll(x);
    if(y) tpy = 63 - __builtin_clzll(y);
    while((tpx>=0 && tpy >= 0) && (x>>tpx & 1) ^ (y>>tpy & 1) == 0) {
        tpx--, tpy--;
        if(tpx==-1 || tpy==-1) break;
    }
    tpx++, tpy++;
    if(min(tpx, tpy) < 3) {
        int ans = 4e18;
        for(int i = 0; i <= 59; i++) {
            int vx = x >> i;
            for(int j = 0; j <= 59; j++) {
                int vy = y >> j;
                if (vy == vx) {
                    ans = min(ans, dp[i][j]);
                    break;
                }
            }
        }
        cout << ans << nl;
        return;
    }

    int req = tpx+tpy;
    int L = 0, R = 16, ans = 0;
    while(L<=R) {
        int M = (L+R)>>1;
        int sum = M * (M+1) / 2;
        if(sum >= req) {
            R = M - 1, ans = M;
        } else {
            L = M + 1;
        }
    }
    int ans2 = 0;
    int d = ans * (ans + 1) / 2 - tpx - tpy;
    for(int i = ans; i>0; i--) {
        if(i==d) continue;
        ans2 += 1LL<<i;
    }
    cout << ans2 << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    pre();
    cin >> t;
    while (t--) shiina_mashiro();
}
