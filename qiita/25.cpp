// Problem: How Many Islands?
// Contest: Volume11 - 1160
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
// Time Limit: 1000
// Start: 2024/08/23 17:01:16

//minimal template
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
    while(1) {
        int w, h; cin >> w >> h;
        if(w == 0 && h == 0) return;
        vector<vector<int>> grid(h, vector<int>(w, 0)), vis(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> grid[i][j];
        
        debug(grid);
        const pair<int, int> dirs[8] = {{0, 1}, {1, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 0}, {1, -1}, {-1, 1}};
        auto dfs = [&](auto&&s, int y, int x) -> void {
            vis[y][x] = 1;
            for(auto&[dy, dx] : dirs) {
                int ny = y + dy, nx = x + dx;
                if(nx < 0 || nx >= w || ny < 0 || ny >= h || vis[ny][nx] || !grid[ny][nx]) continue;
                s(s, ny, nx);
            }
        };

        int comp = 0;
        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
            if(!vis[i][j] && grid[i][j]) {
                dfs(dfs, i, j);
                comp++;
            }
        }
        cout << comp << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

