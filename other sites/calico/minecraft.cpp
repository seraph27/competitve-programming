#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(auto&a: grid) cin >> a;
    int dp[n][m][2][2][2]; 
    memset(dp, 0xc0, sizeof(dp));
    dp[0][0][0][0][0] = (grid[0][0] == 'D');
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int buc : {0, 1}){
                for(int ii : {0, 1}){
                    for(int jj : {0, 1}){
                        if(!buc){
                            ckmax(dp[i][j][1][1][1], dp[i][j][buc][ii][jj]);
                            if(i-1>=0) ckmax(dp[i][j][1][1][1], dp[i-1][j][buc][ii][jj] + (grid[i][j] == 'D'));
                            if(j-1>=0) ckmax(dp[i][j][1][1][1], dp[i][j-1][buc][ii][jj] + (grid[i][j] == 'D'));
                        }
                        if(i-1>=0 && (grid[i][j]!='L' || ii)) {
                            ckmax(dp[i][j][buc][ii][0], dp[i-1][j][buc][ii][jj] + (grid[i][j] == 'D'));
                        }
                        if(j-1>=0 && (grid[i][j]!='L' || jj)) {
                            ckmax(dp[i][j][buc][0][jj], dp[i][j-1][buc][ii][jj] + (grid[i][j] == 'D'));
                        }
                    }
                }
            }
        }
    }
    int ans = -INT_MAX;
    for(int buc = 0; buc < 2; buc++) {
        for(int ii = 0; ii < 2; ii++) {
            for(int jj = 0; jj < 2; jj++) {
                ckmax(ans, dp[n-1][m-1][buc][ii][jj]);
            }
        }
    }
    if(ans < 0) cout << "IMPOSSIBLE" << nl;
    else cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}