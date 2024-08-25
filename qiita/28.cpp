// Problem: Breadth First Search
// Contest: ALDS1 - ALDS1_11_C
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja
// Time Limit: 1000
// Start: 2024/08/24 10:12:31

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
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n; i++) {
        int id, p; cin >> id >> p;
        for(int j = 0; j < p; j++) {
            int x; cin >> x;
            adj[id].pb(x);
        }
    }

    queue<pair<int, int>> bfs;
    bfs.push({1, 0});
    vector<int> vis(n+1, 0), dep(n+1, -1);
    dep[1] = 0;
    while(!bfs.empty()) {
        auto [tp, depth] = bfs.front(); bfs.pop();
        vis[tp] = 1;
        for(auto &e : adj[tp]) {
            if(!vis[e]) {
                dep[e] = depth+1;
                bfs.push({e, depth+1});
                vis[e] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << i << " " << dep[i] << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

