// Problem: D - Sum of Maximum Weights
// Contest: AtCoder Beginner Contest 214
// URL: https://atcoder.jp/contests/abc214/tasks/abc214_d
// Time Limit: 2000
// Start: Wed Jan  7 00:44:57 2026
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
#define eb emplace_back
#define db double

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

const char nl = '\n';

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> siz, par;

    DSU(int n) : siz(n, 1) {
        par.assign(n, 0);
        iota(all(par), 0);
    }

    int find(int x) {
        return x == par[x] ? x : x = find(par[x]); 
    }

    bool merge(int u, int v) {
        if(find(u) == find(v)) return false;
        if(siz[u] < siz[v]) swap(u, v);
        siz[u] += siz[v];
        debug(siz[u], siz[v], u, v);
        par[v] = par[u];
        return true;
    }

};
void shiina_mashiro() {
    int n; cin >> n;
    vector<Edge> vi(n - 1);
    for(size_t i{}; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        vi[i] = {u, v, w};
    }

    sort(all(vi), [&](const Edge &a, const Edge &b){ return a.w < b.w; });
    int ans = 0;
    DSU uf(n);
    for(int i = 0; i < n - 1; i++) {
        auto uu = uf.find(vi[i].u), vv = uf.find(vi[i].v);
        auto usiz = uf.siz[uu], vsiz = uf.siz[vv];
        if(uf.merge(uu, vv)) {
            ans += vi[i].w * usiz * vsiz;
        }
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

