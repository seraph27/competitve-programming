// Problem: F. 1-1-1, Free Tree!
// Contest: Codeforces Round 1037 (Div. 3)
// URL: https://codeforces.com/contest/2126/problem/F
// Time Limit: 4000
// Start: Thu Jul 17 09:07:17 2025
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
    int n, q; cin >> n >> q;
    vector<int> color(n);
    for(int i = 0; i < n; i++) cin >> color[i];

    vector<vector<pii>> adj(n);
    vector<int> deg(n);
    int ans = 0;
    for(int i = 0; i < n-1; i++) {
        int u, v, c; cin >> u >> v >> c;
        --u; --v;
        if(color[u] != color[v]) ans+=c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
        deg[u]++;
        deg[v]++;
    }
    const int B = 444;
    vector<int> heavy;
    for(int i = 0; i < n; i++) if(deg[i] > B) heavy.pb(i);

    auto getidx = [&](int x) -> int {
        return lower_bound(all(heavy), x) - heavy.begin();
    };
    vector<map<int, int>> heavy_color(sz(heavy));
    vector<vector<pii>> heavy_adj(sz(heavy));
    for(int i = 0; i < sz(heavy); i++) {
        auto v = heavy[i];
        for(auto&[e, c]: adj[v]) {
            heavy_color[i][color[e]]+=c;
            if(deg[e] > B){
                heavy_adj[i].pb({e, c});
            }
        }
    }

    for(;q--;) {
        int v, x; cin >> v >> x;
        --v;
        int old = color[v];
        if(old != x) {
            if(deg[v] > B) {
                auto idx = getidx(v);
                ans += heavy_color[idx][old];
                ans -= heavy_color[idx][x];
                for(auto&[e, c] : heavy_adj[idx]) {
                    auto idx = getidx(e);
                    heavy_color[idx][old] -= c;
                    heavy_color[idx][x] += c;
                }
            } else {
                for(auto&[e, c] : adj[v]) {
                    if(color[e] == x) ans-=c;
                    if(color[e] == old) ans+=c;
                    if(deg[e] > B) {
                        auto idx = getidx(e);
                        heavy_color[idx][old]-=c;
                        heavy_color[idx][x]+=c;
                    }
                }
            }
            color[v] = x;
        }
        cout << ans << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

