// Problem: Daruma Otoshi
// Contest: Volume16 - 1611
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=en
// Time Limit: 8000
// Start: 2024/08/29 21:11:52

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
    while(true) {
        int n; cin >> n;
        if(n==0) break;
        vector<int> vi(n); 
        for(auto&a: vi) cin >> a;
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i+len <= n; i++) {
                debug(i, len);
                if(dp[i+1][i+len-1]+2 == len && abs(vi[i] - vi[i+len-1]) <= 1) dp[i][i+len] = len;
                else {
                    for(int k = i; k <= len+i; k++) {
                        ckmax(dp[i][i+len], dp[i][k] + dp[k][i+len]);
                    }
                }
            }
        }

        cout << dp[0][n] << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

