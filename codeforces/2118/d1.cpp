// Problem: D1. Red Light, Green Light (Easy version)
// Contest: Codeforces Round 1030 (Div. 2)
// URL: https://codeforces.com/contest/2118/problem/D1
// Time Limit: 4000
// Start: Thu Jun 12 15:23:23 2025
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

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<int> vi(n), d(n);
    for(auto&a : vi) cin >> a;
    for(auto&a: d) cin >> a;

    vector<int> L(n), R(n);
    for(int i = 0; i < n; i++) {
        R[i] = (i+1 < n ? vi[i+1] - vi[i] : (int)1e15 - vi[i]);
        R[i] %= k;
        L[i] = (i-1 >=0 ? vi[i] - vi[i-1] : vi[i]);
        L[i] %= k;
    }

    vector<int> g(2 * n * k, -1);
    for(int i = 0; i < n; i++) for(int j = 0; j < 2; j++) for(int t = 0; t < k; t++) {
        int idx = (i*2 + j) * k + t;
        int nxt = (j ? L[i] : R[i]); //j==1 go reverse (L)
        int pos = (j ? i-1 : i+1);
        if(pos < 0 || pos >= n) g[idx] = -1;
        else {
            int nt = (t + nxt) % k;
            int nj = (nt == d[pos] ? j^1 : j);
            g[idx] = (pos * 2 + nj) * k + nt;
        }
    }
    
    vector<int> vis(2*n*k, 0), ok(2*n*k, 0);
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        int v = g[u];
        if(v == -1) {
            ok[u] = 1;
        } else {
            if(!vis[v]) s(s, v);
            ok[u] = ok[v];
        }
        vis[u] = 2;
    };
    for(int i = 0; i < 2*n*k; i++) if(!vis[i]) dfs(dfs, i);
    int q; cin >> q;
    for(;q--;) {
        int x; cin >> x;
        int it = lower_bound(all(vi), x) - vi.begin();
        if(it == n) {
            cout << "Yes" << nl;
            continue;
        } else {
            int t0 = ((vi[it] - x) % k + k) % k;
            int dir = (t0 == d[it] ? 1 : 0);
            int id0 = ((it * 2 + dir) * k + t0);
            cout << (ok[id0] ? "Yes" : "No") << nl;
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

