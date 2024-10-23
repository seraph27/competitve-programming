// Problem: F - Road Blocked
// Contest: パナソニックグループ プログラミングコンテスト2024（AtCoder Beginner Contest 375）
// URL: https://atcoder.jp/contests/abc375/tasks/abc375_f
// Time Limit: 2500
// Start: Mon Oct 14 02:45:23 2024
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
    int n, m, q; cin >> n >> m >> q;
    vector<ar<int, 3>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u--, v--;
        edges[i] = {u, v, c};
    }
    vector<vector<pair<int, int>>> adj(n);
    vector<ar<int, 3>> queries(q);
    vector<bool> blocked(m);
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            x--;
            blocked[x] = 1; 
            queries[i] = {t, x, 0};
        } else {
            int x, y; cin >> x >> y;
            x--, y--;
            queries[i] = {t, x, y};
        }
    }

    ll dist[n+1][n+1];
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++) if(!blocked[i]) {
        auto [u, v, c] = edges[i]; 
        dist[u][v] = dist[v][u] = c;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ckmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<ll> ans;
    for(int o = q-1; o >= 0; o--) {
        auto [tp, x, y] = queries[o];
        if(tp == 1) {
            auto [u, v, c] = edges[x];
            ckmin(dist[u][v], (ll)c);
            ckmin(dist[v][u], (ll)c);
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                ckmin(dist[i][j], dist[i][u] + c + dist[v][j]);
                ckmin(dist[i][j], dist[i][v] + c + dist[u][j]);
            }
        } else {
            ans.pb(dist[x][y]);
        }
    }
    debug(queries);
    for(int i = sz(ans)-1; i >= 0; i--) cout << (ans[i] >= 2e18 ? -1 : ans[i]) << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

