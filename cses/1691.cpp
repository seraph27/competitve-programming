// Problem: Mail Delivery
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1691
// Time Limit: 1000
// Start: Wed Jul 16 16:01:14 2025
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

struct Edge {
    int to, rev;
    bool used;
};

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<Edge>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb({v, sz(adj[v]), false});
        adj[v].pb({u, sz(adj[u])-1, false});
    }

    for(int u = 0; u < n; u++) if(sz(adj[u])&1) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    vector<int> euler, st, it(n, 0);
    st.pb(0);
    while(!st.empty()) {
        auto tp = st.back();
        if(it[tp] < sz(adj[tp])) {
            auto &e = adj[tp][it[tp]++];
            if(!e.used) {
                e.used = adj[e.to][e.rev].used = true;
                st.pb(e.to);
            }
        } else {
            euler.pb(tp+1);
            st.pop_back();
        }
    }

    if(sz(euler) < m+1) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    cout << euler << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

