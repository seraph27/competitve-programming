// Problem: C - Make Isomorphic
// Contest: AtCoder Beginner Contest 371
// URL: https://atcoder.jp/contests/abc371/tasks/abc371_c
// Time Limit: 2000
// Start: 2024/09/14 21:00:24

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
    //change H only, so try generating all permutations of H, and calculate how much u need to change, 
    //
    int n; cin >> n;
    int mg; cin >> mg;
    vector<vector<int>> g(n+1, vector<int>(n+1, 0)), h(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < mg; i++) {
        int u, v; cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    int mh; cin >> mh;
    for(int i = 0; i < mh; i++) {
        int u, v; cin >> u >> v;
        h[u][v] = 1;
        h[v][u] = 1;
    }
    debug(h, g);
    vector<vector<int>> cost(n+1, vector<int>(n+1, 0));
    for(int i = 1; i < n; i++) for(int j = i+1; j <= n; j++) {
        int c; cin >> c;
        cost[i][j] = c;
    }
    debug(cost);
    
    ll ans = 4e18;
    vector<int> nodes(n);
    iota(all(nodes), 1);
    do {
        ll add = 0;
        for(int i = 1; i < n; i++) for(int j = i+1; j <= n; j++) {
            if(g[i][j] && !h[nodes[i-1]][nodes[j-1]]) {
                if(nodes[i-1] > nodes[j-1]) add+=cost[nodes[j-1]][nodes[i-1]];
                else add+=cost[nodes[i-1]][nodes[j-1]];
            }
            if(!g[i][j] && h[nodes[i-1]][nodes[j-1]]) {
                if(nodes[i-1] > nodes[j-1]) add+=cost[nodes[j-1]][nodes[i-1]];
                else add+=cost[nodes[i-1]][nodes[j-1]];
            }
        }
        ckmin(ans, add);
    } while(next_permutation(all(nodes)));
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

