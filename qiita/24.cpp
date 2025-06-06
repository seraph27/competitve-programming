// Problem: Depth First Search
// Contest: ALDS1 - ALDS1_11_B
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B
// Time Limit: 1000
// Start: 2024/08/23 16:23:57

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
        int id, k; cin >> id >> k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            adj[id].pb(x);
        }
    }
    for(auto &vi : adj) sort(all(vi));
    
    debug(adj);
    vector<int> vis(n+1, 0), in(n+1), out(n+1);
    int time = 0;
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        for(auto &e: adj[u]) {
            if(!vis[e]) {
                time++;
                in[e] = time;
                s(s, e);
                time++;
                out[e] = time;
            }
        }
    };
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            in[i] = ++time;
            dfs(dfs, i);
            out[i] = ++time;
        }    
    }
    debug(in, out);
    for(int i = 1; i <= n; i++) {
        cout << i << " " << in[i] << " " << out[i] << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

