// Problem: Distinct Routes
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1711
// Time Limit: 1000
// Start: Thu Aug 21 13:30:18 2025
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

struct Dinic {
    struct Edge { int to, rev, cap; bool real; };
    int n, s, t;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n): n(n), g(n), level(n), it(n) {}

    void add_edge(int u, int v, int c) {
        Edge a{v, (int)g[v].size(), c, true};
        Edge b{u, (int)g[u].size(), 0, false};
        g[u].pb(a);
        g[v].pb(b);
    }

    bool bfs() {
        fill(all(level), -1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : g[u]) if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
        return level[t] >= 0;
    }

    int dfs(int u, int f) {
        if (!f || u == t) return f;
        for (int &i = it[u]; i < sz(g[u]); i++) {
            auto &e = g[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1) {
                int pushed = dfs(e.to, min(f, e.cap));
                if (pushed) {
                    e.cap -= pushed;
                    g[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow(int S, int T) {
        s = S; t = T;
        int flow = 0;
        while (bfs()) {
            fill(all(it), 0);
            while (int pushed = dfs(s, 4e18)) flow += pushed;
        }
        return flow;
    }

    vector<vector<int>> recover_path(int S, int T) {
        vector<vector<int>> paths;
        while (true) {
            vector<int> par_v(n, -1), par_e(n, -1);
            queue<int> q; q.push(S); par_v[S] = S;
            while (!q.empty() && par_v[T] == -1) {
                int u = q.front(); q.pop();
                for (int i = 0; i < sz(g[u]); i++) {
                    auto &e = g[u][i];
                    if (par_v[e.to] == -1 && e.real && g[e.to][e.rev].cap > 0) {
                        par_v[e.to] = u; par_e[e.to] = i;
                        q.push(e.to);
                    }
                }
            }
            if (par_v[T] == -1) break;
            vector<int> path;
            for (int v = T; v != S; v = par_v[v]) path.pb(v);
            path.pb(S);
            reverse(all(path));
            for (int v = T; v != S; v = par_v[v]) {
                int u = par_v[v], i = par_e[v];
                auto &e = g[u][i];
                e.cap += 1;
                g[e.to][e.rev].cap -= 1;
            }
            paths.pb(path);
        }
        return paths;
    }
};

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    Dinic d(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        d.add_edge(a, b, 1);
    }
    auto ans = d.max_flow(0, n-1);
    cout << ans << nl;
    auto res = d.recover_path(0, n-1);
    for(auto &p : res) {
        cout << sz(p) << nl;
        for(auto&x : p) cout << x + 1 << " ";
        cout << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

