// Problem: F. Romantic Renovation Rescue
// Contest: Code-X-Culture 25
// URL: https://codeforces.com/gym/615018/problem/F
// Time Limit: 3000
// Start: Tue Jun 10 23:04:37 2025
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
    int n, m, q; cin >> n >> m >> q;
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u;--v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    
    vector<int> blocked(n);
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x') blocked[i] = 1;
    }
    auto f = [&](int start) -> vector<int> {
        vector<int> dist(n, 4e18);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dist[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [dis, node] = pq.top(); pq.pop();
            if(dis != dist[node] || blocked[node]) continue;
            for(auto &[to, cost] : adj[node]) {
                if(ckmin(dist[to], dis + cost)) {
                    pq.push({dist[to], to});
                }
            }
        }
        return dist;
    };

    for(int i = 0; i < q; i++) {
        int type; cin >> type;
        if(type == 0) {
            int x, y; cin >> x >> y;
            --x; --y;
            auto res = f(x);
            debug(res);
            cout << (res[y] > 2e18 || blocked[x] || blocked[y] ? -1 : res[y]) << nl;
        } else {
            int x; cin >> x;
            --x;
            blocked[x] ^= 1;
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

