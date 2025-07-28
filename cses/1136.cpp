// Problem: Counting Paths
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1136
// Time Limit: 1000
// Start: Mon Jul 21 09:38:27 2025
// mintemplate
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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};
const char nl = '\n';

const int LOG = 20;
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<vector<int>> up(n+1, vector<int>(LOG, 0));
    vector<int> depth(n+1, 0);
    auto dfs = [&](auto&&s, int u, int p, int d) -> void {
        depth[u] = d;
        for(auto&e : adj[u]) if(e != p) {
            up[e][0] = u;
            for(int k = 1; k < LOG; k++) {
                up[e][k] = up[up[e][k-1]][k-1];
            }
            s(s, e, u, d + 1);
        }
    };
    dfs(dfs, 1, -1, 0);

    auto lca = [&](int a, int b) -> int {
        if(depth[a] < depth[b]) swap(a, b);
        int D = depth[a] - depth[b];
        for(int i = 0; i < LOG; i++) if((D >> i) & 1) a = up[a][i];
        for(int i = LOG-1; ~i; i--) if(up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
        return (a==b ? a : up[a][0]);
    };
    
    vector<int> cnt(n+1);
    auto upd = [&](int a, int b) -> void {
        cnt[a]++;
        cnt[b]++;
        int c = lca(a, b);
        cnt[c]--;
        cnt[up[c][0]]--;
    };
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        upd(a, b);
    }

    auto dfs2 = [&](auto&&s, int u, int p) -> void {
        for(auto&e: adj[u]) if(e != p) {
            s(s, e, u);
            cnt[u] += cnt[e];
        }
    };
    dfs2(dfs2, 1, -1);
    for(int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

