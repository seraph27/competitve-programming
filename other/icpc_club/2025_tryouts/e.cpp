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
#define eb emplace_back
#define db double

using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    int n, k; cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];

    map<int, vector<pii>> mp;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        mp[grid[i][j]].eb(i, j);
    }
    
    for(int i = 1; i <= k; i++) if(mp[i].empty()) {
        cout << -1 << nl;
        return;
    }

    const int INF = 4e18; 
    vector dp(n, vector(n, vector<int>(k+1, INF)));

    for (auto &[x, y] : mp[1]) dp[x][y][1] = 0;

    for (int num = 2; num <= k; num++) {
        for (auto &[x1, y1] : mp[num - 1]) {
            int now = dp[x1][y1][num - 1];
            if (now >= INF) continue;
            for (auto &[x2, y2] : mp[num]) {
                int dist = abs(x1 - x2) + abs(y1 - y2);
                ckmin(dp[x2][y2][num], now + dist);
            }
        }
    }

    int ans = INF;
    for (auto &[x, y] : mp[k]) ckmin(ans, dp[x][y][k]);
    if (ans >= INF) ans = -1;
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
