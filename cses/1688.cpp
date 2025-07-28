// Problem: Company Queries II
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1688
// Time Limit: 1000
// Start: Sat Jul 19 09:48:44 2025
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
    vector<int> par(n+1), depth(n+1);
    vector<vector<int>> adj(n+1);
    par[1] = -1;
    for(int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].pb(i);
    }

    auto dfs = [&](auto&&s, int u, int d) -> void {
        depth[u] = d;
        for(auto&e : adj[u]) s(s, e, d + 1);
    };
    dfs(dfs, 1, 0);

    vector<vector<int>> up(n+1, vector<int>(20));
    for(int i = 1; i <= n; i++) up[i][0] = par[i];
    for(int k = 1; k < 20; k++) for(int i = 1; i <= n; i++) {
        up[i][k] = (up[i][k-1] == -1 ? -1 : up[up[i][k-1]][k-1]);
    }

    auto lft = [&](int x, int y) -> int {
        for(int k = 0; k < 20; k++) {
            if((y >> k) & 1) {
                x = up[x][k];
                if(x==-1) break;
            }
        }
        return x;
    };

    auto lca = [&](int a, int b) -> int {
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        a = lft(a, diff);
        for(int k = 20; k >= 0; k--) {
            auto f = lft(a, 1 << k), g = lft(b, 1 << k);
            if(f==g) continue;
            a = f, b = g;
        }
        if(a==b) return a;
        return par[a];
    };

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

