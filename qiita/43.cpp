// Problem: D - パ研軍旗
// Contest: パ研合宿2019　第3日「パ研杯2019」
// URL: https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
// Time Limit: 1000
// Start: 2024/08/27 15:58:32

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<string> grid(5);
    for(auto&a: grid) cin >> a; 
    
    for(int i = 0; i < 5; i++) for(int j = 0; j < n; j++) {
        if(grid[i][j] == 'B') grid[i][j] = '0';
        else if(grid[i][j] == 'W') grid[i][j] = '1';
        else if(grid[i][j] == 'R') grid[i][j] = '2';
        else grid[i][j] = '3';
    }

    debug(grid);
    int dp[n+5][3]; //dp[i][j] := min operations for a good flag when im ith column, and last color was j
    memset(dp, INF, sizeof(dp));
    

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            for(int j = 0; j < 3; j++) {
                int oper = 5;
                for(int k = 0; k < 5; k++) {
                    if(grid[k][0]-'0' == j) --oper;
                }
                dp[0][j] = oper;
            }
        } else {
            for(int j = 0; j < 3; j++) { //last pick
                for(int k = 0; k < 3; k++) { // new pick
                    if(j == k) continue;
                    int oper = 5;
                    for(int z = 0; z < 5; z++) {
                        if(grid[z][i]-'0' == k) --oper;
                    }
                    ckmin(dp[i][k], dp[i-1][j] + oper);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 3; i++) {
        ckmin(ans, dp[n-1][i]);
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

