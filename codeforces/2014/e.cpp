 / Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
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
const int INF = 0x3f3f3f3f;


void shiina_mashiro() {
    int n, m, h; cin >> n >> m >> h;
    vector<int> horse(h);
    for(auto&a: horse) {
        cin >> a; --a;
    }
    vector<vector<ar<ll, 2>>> adj(2*n);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        --u;--v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        adj[u+n].pb({v+n, w/2});
        adj[v+n].pb({u+n, w/2});
    }
    for(int i = 0; i < h; i++) {
            adj[horse[i]].pb({horse[i]+n, 0});
    }
    
    auto dijk = [&](int start) -> vector<ll> {
        priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
        vector<ll> vtx1(2*n, 4e18);
        vtx1[start] = 0;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [d, v] = pq.top(); pq.pop();
            if(d != vtx1[v]) continue;
            for(auto &[e, w]: adj[v]) {
                if(ckmin(vtx1[e], d + w)) {
                    pq.push({vtx1[e], e});
                }
            }
        }
        return vtx1;
    };

    auto robin = dijk(0), mar = dijk(n-1);
    ll ans = 4e18;
    for(int i = 0; i < n; i++) {
        debug(robin[i], robin[i+n], mar[i], mar[i+n], i);
        ckmin(ans, max(min(robin[i], robin[i+n]), min(mar[i], mar[i+n])));
    }

    cout << (ans==4e18 ? -1 : ans) << nl;
}


int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}


