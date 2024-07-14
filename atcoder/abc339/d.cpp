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
    int n; cin >> n;
    vector<string> g(n);
    for(auto&a: g) cin >> a;
    const pii dirs[4]  = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int P1 = -1, P2 = -1; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == 'P') {
                if(P1<0) P1 = i*n+j;
                else P2 = i*n+j;
            }
        }
    }
    queue<pii> bfs;
    vector<vector<int>> dist(n*n, vector<int>(n*n, INF));
    dist[P1][P2] = 0;
    bfs.push({P1, P2});
    while(!bfs.empty()){
        auto [p1, p2] = bfs.front(); bfs.pop();
        auto p1x = p1/n, p1y = p1%n, p2x = p2/n, p2y = p2%n;
        if(p1 == p2) {
            cout << dist[p1][p2] << nl;
            return;
        }

        for(auto &[dx, dy] : dirs) {
            auto chk = [&](auto x, auto y) -> ar<int, 2> {
                int nx = x + dx, ny = y + dy;
                if(nx < 0 || ny < 0 || nx >= n || ny >= n || g[nx][ny] == '#') return {x, y};
                return{nx, ny};
            };
            auto tst1 = chk(p1x, p1y);
            auto tst2 = chk(p2x, p2y);
            int np1 = tst1[0]*n+tst1[1], np2 = tst2[0]*n+tst2[1];
            if(ckmin(dist[np1][np2], dist[p1][p2]+1)){
                bfs.push({np1, np2});
            }
        }
    }
    cout << -1 << nl;



}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

