// Problem: D. Iris and Game on the Tree
// Contest: Codeforces Round 969 (Div. 2)
// URL: https://codeforces.com/contest/2007/problem/D
// Time Limit: 2000
// Start: 2024/08/30 22:37:51

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
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    string s; cin >> s;

    map<char, int> mp;
    mp['0'] = 0, mp['1'] = 1, mp['?'] = 2;

    vector<int> leafs(3, 0);
    int notleafs = 0;
    auto dfs = [&](auto &&ds, int u, int p) -> void {
        if(adj[u].size()==1 && adj[u][0] == p) leafs[mp[s[u]]]++;
        else if(u!=0 && s[u] == '?') notleafs++;
        for(auto &e: adj[u]) if(e != p) {
            ds(ds, e, u);
        }
    };
    dfs(dfs, 0, -1);
    
    int root = mp[s[0]];
    if(root == 2) {
        if(leafs[0] != leafs[1]) {
            cout << max(leafs[0], leafs[1]) + leafs[2] / 2 << nl;
        } else {
            cout << max(leafs[0], leafs[1]) + (leafs[2] + (notleafs&1)) / 2 << nl;
        }
    } else {
        cout << leafs[root ^ 1] + (leafs[2] + 1) / 2 << nl;
    }
    debug(leafs, notleafs);

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
