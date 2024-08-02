#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int rt = a[1];
    vector<vector<int>> adj(n+1);
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        adj[i].pb(x);
        adj[x].pb(i);
    }

    auto dfs = [&](auto&&s, int u, int p) -> int {
        auto mn = INF;
        for(auto &e : adj[u]) {
            if(e != p) {
                ckmin(mn, s(s, e, u));
            }
        }
        ckmin(a[u], mn);
        if(mn!=INF) {
            int diff = (mn-a[u])/2;
            a[u]+=diff;
            mn+=diff;
        }
        return a[u];
    };

    dfs(dfs, 1, -1);
    int mx = INF;

    for(auto &e : adj[1]) ckmin(mx, a[e]);
    cout<<rt+mx<<nl;
}

int main() {   
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

