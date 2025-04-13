// Problem: E1. The Game (Easy Version)
// Contest: Ethflow Round 1 (Codeforces Round 1001, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2062/problem/E1
// Time Limit: 4000
// Start: 2025/01/27 0:55:54
// mintemplate
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

struct fenwick {
    vector<int> bit;
    int n;
    fenwick(int _n) : n(_n) {
        bit.assign(n+1, 0);
    }
    void add(int x, int val) {
        for(++x; x <= n; x += x & -x) {
            bit[x] += val;
        }
    }
    int sum(int x) {
        int res = 0;
        for(++x; x > 0; x -= x & -x) {
            res += bit[x];
        }
        return res;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l-1);
    }    
};

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> val(n);
    for(auto&x: val) cin >> x;
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> idxs(n);
    iota(all(idxs), 0);
    sort(all(idxs), [&](int a, int b) {return val[a] > val[b];});

    vector<int> tin(n), tout(n);
    int t = 0;
    auto dfs = [&](auto &&ss, int u, int p) -> void {
        tin[u] = t++;
        for(auto &e : adj[u]) if(e != p) {
            ss(ss, e, u);
        }
        tout[u] = t-1;
    };
    dfs(dfs, 0, -1);
    debug(tin, tout);

    fenwick fw(n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        vector<int> tmp;
        tmp.pb(idxs[i]);
        while(i+1 < n && val[idxs[i]] == val[idxs[i+1]]) {
            i++;
            tmp.pb(idxs[i]);
        }
        for(auto &x : tmp) {
            auto query = fw.sum(tin[x], tout[x]);
            debug(x, query);
            if(query < k) {
                cout << x+1 << nl;
                return;
            }
        }
        for(auto &x : tmp) {
            fw.add(tin[x], 1);
            k++;
        }
    }
    cout << "0" << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

