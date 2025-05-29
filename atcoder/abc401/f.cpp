// Problem: F - Add One Edge 3
// Contest: AtCoder Beginner Contest 401
// URL: https://atcoder.jp/contests/abc401/tasks/abc401_f
// Time Limit: 2000
// Start: Thu May 22 02:39:29 2025
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
    int n1; cin >> n1;
    vector<vector<int>> g1(n1);
    for(int i = 0; i < n1-1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        g1[a].pb(b);
        g1[b].pb(a);
    }
    int n2; cin >> n2;
    vector<vector<int>> g2(n2);
    for(int i = 0; i < n2-1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        g2[a].pb(b);
        g2[b].pb(a);
    }
    
    vector<int> down, up;
    auto dfs1 = [&](auto&&s, int u, int p, auto&adj) -> void {
        for(auto& e : adj[u]) if(e != p) {
            s(s, e, u, adj);
            ckmax(down[u], down[e] + 1);
        }
    };

    auto dfs2 = [&](auto&&s, int u, int p, auto&adj) -> void {
        int mx1 = -1, mx2 = -1;
        for(int &e : adj[u]) if(e != p) {
            int d = down[e] + 1;
            if(d > mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if(d > mx2) {
                mx2 = d;
            }
        }
        for(int &e : adj[u]) if(e != p) {
            int use = (down[e] + 1 == mx1 ? mx2 : mx1);
            up[e] = 1 + max(up[u], (use < 0 ? 0 : use));
            s(s, e, u, adj);
        }
    };

    auto get_depth = [&](int n, auto&g) -> vector<int> {
        down.assign(n, 0);
        up.assign(n, 0);
        dfs1(dfs1, 0, -1, g);
        dfs2(dfs2, 0, -1, g);
        vector<int> height(n);
        for(int i = 0; i < n; i++) {
            height[i] = max(down[i], up[i]);
        }
        return height;
    };

    auto dia1 = get_depth(n1, g1);
    auto dia2 = get_depth(n2, g2);
    
    int d1 = *max_element(all(dia1));
    int d2 = *max_element(all(dia2));
    int D = max(d1, d2);
    sort(all(dia2));    
    vector<int> pref(n2+1);
    for(int i = 0; i < n2; i++) {
        pref[i+1] = pref[i] + dia2[i] + 1;
    }
    int ans = 0;
    for(int i = 0; i < n1; i++) {
        auto k = lower_bound(all(dia2), D - dia1[i]) - dia2.begin();
        int bad = D * k;
        int good = (n2-k) * dia1[i] + pref[n2] - pref[k];
        ans += good + bad;
    }
    cout << ans << nl;
    debug(dia1, dia2);
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}

