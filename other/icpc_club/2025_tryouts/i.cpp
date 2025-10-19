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
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<bool> friends(k + 1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        friends[x] = true;
    }

    vector<vector<int>> adj(k + 1);
    vector<int> outdeg(k + 1);

    map<pii, int> edges;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        if(friends[b]) outdeg[a]++;
        if(friends[a]) outdeg[b]++;
        if(a == b && !friends[a]) outdeg[a]++;
        edges[{a, b}]++;
    }
    
    int ans = 0;
    int add1 = -1, add2 = -1;
    for(int u = 1; u <= k; u++) {
        if(friends[u]) continue;
        for(int v : adj[u]) {
            if(u == v) continue;
            if(!friends[v]) {
                if(ckmax(ans, edges[{u, v}] + edges[{v, u}] + outdeg[u] + outdeg[v])) {
                    add1 = u;
                    add2 = v;
                }
            }
        }
    }
    vector<pii> tmp;
    for(int i = 1; i <= k; i++) if (!friends[i]) tmp.pb({outdeg[i], i});
    sort(all(tmp), greater<pii>());
    if (sz(tmp) >= 2) if (ckmax(ans, tmp[0].first + tmp[1].first)) {
        add1 = tmp[0].second;
        add2 = tmp[1].second;
    }
    if (sz(tmp) >= 1) if (ckmax(ans, tmp[0].first)) {
        add1 = tmp[0].second;
        add2 = -1;
    }
    debug(add1, add2);
    if(add1 != -1) friends[add1] = true;
    if(add2 != -1) friends[add2] = true;

    int tot = 0;
    for (auto &e : edges) {
        int u = e.first.first, v = e.first.second;
        if (friends[u] && friends[v]) tot += e.second;
    }
    cout << tot << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
