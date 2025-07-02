// Problem: Planets Queries I
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1750
// Time Limit: 1000
// Start: 2025/07/01 13:01:30
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
    int n, query; cin >> n >> query;
    vector<int> to(n);
    vector<vector<int>> rev(n);
    vector<int> indeg(n, 0);
    for(int i = 0; i < n; i++) {
        int dest; cin >> dest;
        --dest;
        indeg[dest]++;
        to[i] = dest;
        rev[dest].pb(i);
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(indeg[i] == 0) q.push(i);
    while(!q.empty()) {
        auto f = q.front(); q.pop();
        int nxt = to[f];
        indeg[nxt]--;
        if(indeg[nxt] == 0) {
            q.push(nxt);
        }
    }
    vector<int> vis(n, 0);
    vector<int> where(n, 0);
    vector<int> pos(n, 0);
    vector<vector<int>> cycles;
    int idx = 0;
    for(int i = 0; i < n; i++) {
        vector<int> cyc;
        if(!vis[i] && indeg[i] == 1) {
            for(auto cur = i; !vis[cur]; cur = to[cur]) {
                vis[cur] = 1;
                cyc.pb(cur);
                where[cur] = idx;
                pos[cur] = sz(cyc) - 1;
            }
        }
        if(sz(cyc)) {
            idx++;
            cycles.pb(cyc);
        }
    }
    
    vector<int> dist_to_cyc(n, -1);
    queue<int> q2;
    for(int i = 0; i < n; i++) {
        if(vis[i]) {
            dist_to_cyc[i] = 1;
            q2.push(i);
        }
    }
    while(!q2.empty()) {
        auto u = q2.front(); q2.pop();
        for(int &e : rev[u]) {
            if(dist_to_cyc[e] == -1) {
                dist_to_cyc[e] = dist_to_cyc[u] + 1;
                q2.push(e);
            }
        }
    }
    const int LOG = 40;
    vector<vector<int>> up(LOG, vector<int>(n));
    for(int u = 0; u < n; u++) {
        up[0][u] = to[u];
    }
    for(int j = 1; j < LOG; j++) {
        for(int u = 0; u < n; u++) {
            up[j][u] = up[j-1][up[j-1][u]];
        }
    }

    auto lift = [&](int u, int d) {
        for(int j = 0; j < LOG; j++) {
            if((d >> j) & 1) {
                u = up[j][u];
            }
        }
        return u;
    };
    
    for(int i = 0; i < query; i++) {
        int x, k; cin >> x >> k;
        --x;
        int d = min(k, dist_to_cyc[x]);
        x = lift(x, d);
        k -= d;
        if(k == 0) {
            cout << x + 1 << nl;
            continue;
        }
        auto &f = cycles[where[x]];
        auto nidx = (pos[x] + (k % sz(f))) % sz(f);
        cout << f[nidx] + 1 << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

