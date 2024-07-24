#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, m; cin >> n >> m;
    vector<int> vw(n);
    for(auto&a: vw) cin >> a;
    vector<vector<pii>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }

    vector<ll> vtx(n, 4e18);
    vtx[0] = vw[0];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({vw[0], 0});
    while(!pq.empty()) {
        auto [w, now] = pq.top(); pq.pop();
        if(w != vtx[now]) continue;
        for(auto&[to, edgew] : adj[now]) {
            debug(now, to, edgew);
            if(ckmin(vtx[to], vtx[now] + edgew + vw[to])) {
                pq.push({vtx[to], to});
            }
        }
    }
    for(int i = 1; i < n; i++) cout << vtx[i] << " ";
    cout << nl;
 }

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}
