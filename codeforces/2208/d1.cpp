// Problem: D1. Tree Orientation (Easy Version)
// Contest: Codeforces Round 1086 (Div. 2)
// URL: https://codeforces.com/contest/2208/problem/D1
// Time Limit: 3000
// Start: Sat Mar 14 08:53:14 2026
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    
    vector<pii> edges;
    for(int u = 0; u < n; u++) for(int v = 0; v < n; v++) {
        if(u == v && vi[u][v] == '0') {
            cout << "NO" << nl;
            return;
        }   
        if(u != v && vi[u][v] == '1') {
            bool ok = 1;
            for(int k = 0; k < n; k++) {
                if(k == u || k == v) continue;
                if((vi[u][k] == vi[k][v]) && vi[u][k]-'0') {
                    ok = 0;
                    break;
                } 
            }
            if(ok) edges.pb({u, v});
        }
    }
    if(sz(edges) != n - 1) {
        cout << "NO" << nl;
        return;
    }

    DSU uf(n);
    vector<vector<int>> adj(n);
    for(auto &[u, v] : edges) {
        uf.merge(u, v);
        adj[u].pb(v);
    }

    bool ok = 1;
    for(int i = 0; i < n; i++) {
        vector<int> vis(n, 0);
        queue<int> bfs;
        bfs.push(i);
        vis[i] = 1;
        while(sz(bfs)) {
            auto f = bfs.front(); bfs.pop();
            for(int v : adj[f]) if(!vis[v]) {
                vis[v] = 1;
                bfs.push(v);
            }
        }
        for(int j = 0; j < n; j++) if(vis[j] != vi[i][j] - '0') ok = 0;
    }

    if(!ok || uf.size(0) != n) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        for(auto &[u, v] : edges) cout << u + 1 << " " << v + 1 << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
