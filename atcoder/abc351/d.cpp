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
    vector<vector<int>> vis(h, vector<int>(w, 0));
    const pii dir[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int ans = 0, iter = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            queue<pii> bfs;
            int cnt = 0;
            if(!vis[i][j] && grid[i][j] != '#') {
                debug(i, j);
                iter++;
                bfs.push({i, j});
                vis[i][j] = iter;
            } else continue;
            while(!bfs.empty()) {
                auto [y, x] = bfs.front(); bfs.pop();
                int ok = 1;
                vector<pii> pend;
                cnt++;
                for(auto [dx, dy] : dir) {
                    int newx = x + dx, newy = y + dy;
                    if(newy < 0 || newy >= h || newx < 0 || newx >= w || vis[newy][newx] == iter) continue;
                    if(grid[newy][newx] == '#') {
                        ok = 0;
                        break;
                    }
                    pend.pb({newy, newx});
                }
                if(ok) {
                    for(auto [py, px] : pend) {
                        if(!(vis[py][px]==iter)) {
                            bfs.push({py, px});
                            vis[py][px]=iter;
                        }
                    }
                }
            }
            ckmax(ans, cnt);
        }
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

