// Problem: F - Path to Integer
// Contest: Tokio Marine & Nichido Fire Insurance Programming Contest 2025  (AtCoder Beginner Contest 402)
// URL: https://atcoder.jp/contests/abc402/tasks/abc402_f
// Time Limit: 2000
// Start: Mon Jun  2 16:55:15 2025
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

void solve() {
    int n, mod; cin >> n >> mod;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> rem(2*n+1);
    rem[0] = 1;
    for(int i = 0; i < sz(rem)-1; i++) {
        rem[i+1] = rem[i] * 10;
        rem[i+1] %= mod;
    }
    debug(rem);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> grid[i][j];
        grid[i][j] = (rem[2*(n-1)-i-j] * grid[i][j]) % mod;
    }
    
    if(n==1) {
        cout << grid[0][0] % mod << nl;
        return;
    }
    vector<vector<int>> diagA(n), diagB(n);

    for(int msk = 0; msk < (1 << (n-1)); msk++) {
        int X = 0, Y = 0;
        int sum = grid[Y][X];
        for(int j = 0; j < n-1; j++) {
            if((msk >> j) & 1) { //go right
                sum += grid[Y][X+1];
                X++;
            } else {
                sum += grid[Y+1][X];
                Y++; 
            }
            if(sum > mod) sum -= mod;
        } 
        diagA[Y].pb(sum);
    }

    for(int msk = 0; msk < (1 << (n-1)); msk++) {
        int X = n-1, Y = n-1;
        int sum = grid[Y][X];
        for(int j = 0; j < n-2; j++) {
            if((msk >> j) & 1) {
                sum += grid[Y][X-1];
                X--;
            } else {
                sum += grid[Y-1][X];
                Y--;
            }
            if(sum > mod) sum -= mod;
        }
        diagB[Y].pb(sum);
        diagB[Y-1].pb(sum);
    }
    for(auto &x : diagA) {
        sort_unique(x);
    }
    for(auto &x : diagB) {
        sort_unique(x);
    }
    debug(grid, diagA, diagB);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(auto val : diagA[i]) {
            auto it = lower_bound(all(diagB[i]), mod - val);
            if(it != diagB[i].begin()) --it;
            ckmax(ans, max((val + *it) % mod, (val + *diagB[i].rbegin()) % mod));
        }
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

