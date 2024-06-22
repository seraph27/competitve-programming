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

struct DSU {
    vector<int> parent, sizes;
    DSU(int sz) : parent(sz), sizes(sz, 1) {
        for(int i = 0; i < sz; i++) parent[i] = i;
    }
    int find(int v) {
        return parent[v] == v ? v : (parent[v] = find(parent[v]));
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(sizes[u] < sizes[v]) swap(u, v);
            parent[v] = u;
            sizes[u] += sizes[v];
        }
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

void seraph() {
    int n, m; cin >> n >> m;
    vector<int> w(m), vk(m);
    vector<vector<int>> edges(m);

    for(int i = 0; i < m; i++) {
        int k, c; cin >> k >> c;
        vector<int> vtx(k);
        for(auto&a: vtx) {
            cin >> a;
            --a;
        }
        edges[i] = vtx;
        w[i] = c;
        vk[i] = k;
    }
    vector<int> idx(m);
    DSU uf(n);
    iota(all(idx), 0);
    sort(all(idx), [&](int a, int b) {return w[a] < w[b];});
    ll ans = 0;
    for(int a : idx) {
        for(int i = 1; i < vk[a]; i++) {
            if(!uf.connected(edges[a][0], edges[a][i])) {
                uf.merge(edges[a][0], edges[a][i]);
                ans+=w[a];
            }
        }
    }
    
    cout << (uf.sizes[uf.find(0)] == n ? ans : -1) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

