// Problem: Road Reparation
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1675
// Time Limit: 1000
// Start: Thu Jul 10 13:08:31 2025
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

const char nl = '\n';

struct DSU {
    vector<int> par, siz;

    DSU(){}
    DSU(int x) {
        par.resize(x);
        iota(all(par), 0);
        siz.assign(x, 1);
    }

    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x==y) return false;
        if(siz[x] < siz[y]) swap(x, y);
        siz[x]+=siz[y];
        par[y] = x;
        return true;
    }
};
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<ar<int, 3>> edges;
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        edges.pb({w, a, b});
    }
    
    DSU uf(n);
    int ans = 0;
    sort(all(edges));
    int cnt = 0;
    for(auto &[w, a, b] : edges) {
        if(uf.find(a) != uf.find(b)) {
            ans += w;
            cnt++;
            uf.merge(a, b);
        }
        if(cnt==n-1) {
            cout << ans << nl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

