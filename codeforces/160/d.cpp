// Problem: D. Edges in MST
// Contest: Codeforces Round 111 (Div. 2)
// URL: https://codeforces.com/contest/160/problem/D
// Time Limit: 2000
// Start: Wed Apr  8 12:37:03 2026
// multitest
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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

struct DSU {
    vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

vector<int> bridges(int n, const vector<vector<pii>> &adj) {
    vector<int> tin(n, -1), low(n, 0), vis(n, 0);
    int timer = 0;
    vector<int> res;

    auto dfs = [&](auto &&s, int u, int pe) -> void {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for (auto &[v, id] : adj[u]) {
            if (id == pe) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                s(s, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) res.pb(id);
            }
        }
    };

    for (int i = 0; i < n; i++) if (!vis[i]) dfs(dfs, i, -1);
    return res;
}

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--, edges[i][1]--;
    }

    //thoughts: 
    // 1. do normal kruskals, if some edge is never touched, its obviously not in any MST.
    // 2. for exactly 1 or > 1 MST, equal edges can be either or. the way to check is 
    // if they are in the same component before merging, if they are, then they can be either or, if not, then they must be in the MST.

    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](auto &a, auto &b) {
        return edges[a][2] < edges[b][2];
    });

    //how to check what are the adjacent edges with same weight that cause a new merge to fail?
    //bridges?
    DSU uf(n);
    vector<int> ans(m);
    int comps = n;

    vector<int> id(n, -1);
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[ord[j]][2] == edges[ord[i]][2]) {
            j++;
        }
       //built contracted graph
        int idx = 0;
        vector<int> used;

        for(int k = i; k < j; k++) {
            int u = uf.find(edges[ord[k]][0]), v = uf.find(edges[ord[k]][1]);
            if (id[u] == -1) id[u] = idx++, used.pb(u);
            if (id[v] == -1) id[v] = idx++, used.pb(v);
        }

        vector<vector<pii>> adj(idx);
        for (int k = i; k < j; k++) {
            int u = id[uf.find(edges[ord[k]][0])], v = id[uf.find(edges[ord[k]][1])];
            if (u != v) {
                adj[u].eb(v, k);
                adj[v].eb(u, k);
            }
        }
        for (int k = i; k < j; k++) {
            int u = id[uf.find(edges[ord[k]][0])], v = id[uf.find(edges[ord[k]][1])];
            if (u != v) {
                if (ans[ord[k]] == 0) ans[ord[k]] = 2;
            }
        }
        auto bs = bridges(idx, adj);
        for (int x : bs) {
            ans[ord[x]] = 1;
        }

        for (int k = i; k < j; k++) if(uf.merge(edges[ord[k]][0], edges[ord[k]][1])) comps--;
        for (int x : used) id[x] = -1;
        if(comps == 1) break;
        i = j;
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) cout << "none\n";
        else if (ans[i] == 1) cout << "any\n";
        else cout << "at least one\n";
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
