#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int h, w; cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> energy(h, vector<int>(w, 0));
    int n; cin >> n;
    for(;n--;) {
        int r, c, e; cin >> r >> c >> e;
        --r;--c;
        energy[r][c] = e;
    }
    ar<int, 3> start{};
    int endx, endy;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == 'S') start = {energy[i][j], i, j};
            if(grid[i][j] == 'T') {endx = i, endy = j;}
        }
    }
    if(start[0]==0) {cout << "No" << nl; return;}
    ar<int, 2> dxy[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp(h, vector<int>(w, -1));
    dp[start[1]][start[2]] = 0;
    priority_queue<ar<int, 3>> pq;
    pq.push(start);
    while(!pq.empty()) {
        auto [e, row, col] = pq.top(); pq.pop();
        int depth = max(dp[row][col], energy[row][col]);
        if(depth <= 0) continue;
        for(auto &[dx, dy] : dxy) {
            int nx = row + dx, ny = col + dy;
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || grid[nx][ny] == '#') continue;
            if(ckmax(dp[nx][ny], depth - 1)) pq.push({dp[nx][ny], nx, ny});
        }
    }
    debug(dp);
    cout << (dp[endx][endy] != -1 ? "Yes" : "No") << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

