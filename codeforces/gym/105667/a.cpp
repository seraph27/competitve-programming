// Problem: A. Toy Marbles
// Contest: MITIT Winter 2025 Advanced Round 2
// URL: https://codeforces.com/gym/105667/problem/A
// Time Limit: 2000
// Start: Fri Jul 11 22:33:43 2025
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

struct Node{
    set<int> s;
    int nxt;
};
void shiina_mashiro() {
    int n; cin >> n;
    vector<int> to(n+1);
    vector<Node> g(n+1);
    for(int i = 1; i <= n; i++) {
        int dest; cin >> dest;
        to[i] = dest;
        g[dest].s.insert(i);
        g[i].nxt = dest;
    }
    int ans = 0;

    vector<int> in_cycle(n+1);
    auto cycle = [&]() {
        vector<int> vis(n+1);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int u = i;
            while (!vis[u]) {
                vis[u] = i;
                u = to[u];
            }
            if (vis[u] == i) {
                int v = u;
                do {
                    in_cycle[v] = 1;
                    v = to[v];
                } while (v != u);
            }
        }
    };
    cycle();
    vector<pii> first, second;
    vector<int> vis(n+1, 0);
    for(auto &b : g) {
        if(sz(b.s) < 2) continue;
        int target = -1;
        for(auto &x : b.s) {
            if(in_cycle[x]) {
                target = x;
                break;
            }
        }
        if(target != -1) {
            for(auto&x: b.s) if(x != target) {
                second.pb({target, x});
                ans++;
                vis[x] = 1;
            }
        } else {
            target = *b.s.begin();
            for(auto&x: b.s) if(x != target) {
                second.pb({target, x});
                ans++;
                vis[x] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) debug(g[i].s, g[i].nxt);

    vector<int> topo;
    auto dfs = [&](auto&&s, int u) -> void {
        vis[u] = 1;
        int nx = g[u].nxt;
        if(!vis[nx]) s(s, nx);
        topo.pb(u);
    };
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            topo.clear();
            dfs(dfs, i);
            bool cyc = in_cycle[topo.back()];
            if (cyc) {
                for (int j = 0; j + 1 < sz(topo); j++) {
                first.pb({topo[j], topo[j+1]});
                ans++;
                }
            } else {
                for (int u : topo) {
                    first.pb({u, to[u]});
                    ans++;
                }
            }
        }   
    }
    cout << ans << nl;
    for(auto &[a, b] : second) {
        cout << 2 << " " << a << " " << b << nl;
    }
    for(auto &[a, b] : first) {
        cout << 1 << " " << a << " " << b << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

