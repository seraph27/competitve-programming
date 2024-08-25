// Problem: C - 幅優先探索
// Contest: AtCoder Beginner Contest 007
// URL: https://atcoder.jp/contests/abc007/tasks/abc007_3
// Time Limit: 2000
// Start: 2024/08/24 19:18:02

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
    int r, c; cin >> r >> c;
    int sy, sx; cin >> sy >> sx;
    --sy;--sx;
    int gy, gx; cin >> gy >> gx;
    --gy;--gx;

    vector<string> a(r);
    for(int i = 0; i < r; i++) cin >> a[i];

    queue<ar<int, 3>> bfs;


    vector<vector<int>> vis(r, vector<int>(c, 0));

    bfs.push({sy, sx, 0});
    vis[sy][sx] = 1;
    const ar<int, 2> dirs[4] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!bfs.empty()) {
	auto [y, x, depth] = bfs.front(); bfs.pop();
	vis[y][x] = 1;
	if(y == gy && x == gx) {
	    cout << depth << nl;
	    return;
	}
	for(auto &[dy, dx] : dirs) {
	    int ny = dy + y, nx = dx + x;
	    if(ny < 0 || ny >= r || nx < 0 || nx >= c || vis[ny][nx] || a[ny][nx] == '#') continue;
	    bfs.push({ny, nx, depth+1});
	    vis[ny][nx] = 1;
	}
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

