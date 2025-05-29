// Problem: D. D/D/D
// Contest: Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/contest/2109/problem/D
// Time Limit: 2000
// Start: Sun May 18 03:14:12 2025
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

void shiina_mashiro() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> vi(l);
    for(auto &a : vi) cin >> a;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> even(n, 0), odd(n, 0); // can i visit vertex with even / odd steps
    queue<pair<int, int>> q;
    q.push({0, 0});
    even[0] = 1;
    while(!q.empty()) {
        auto [f, dist] = q.front(); q.pop();
        for(auto &a : adj[f]) {
            int nd = dist + 1;
            if(nd % 2 == 0 && !even[a]) {
                even[a] = nd;
                q.push({a, nd});
            }
            if(nd % 2 && !odd[a]) {
                odd[a] = nd;
                q.push({a, nd});
            }
        }
    }
    int mnodd = 4e18;
    int oddsum = 0, cnt = 0;
    for(int i = 0; i < l; i++) {
        if(vi[i]%2) {
            oddsum += vi[i];
            ckmin(mnodd, vi[i]);
            cnt++;
        }
    }
    int sum = accumulate(all(vi), 0LL);
    int mxodd = sum;
    if(cnt%2 == 0) {
        mxodd = sum - mnodd;
    }
    int mxeven = sum;
    if(cnt%2 == 1) {
        mxeven = sum - mnodd;
    }

    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        if(even[i] && even[i] <= mxeven) ans[i] = 1;
        if(odd[i] && odd[i] <= mxodd) ans[i] = 1;
    }
    ans[0] = 1;
    for(auto &a : ans) {
        cout << a;
    }
    debug(odd, even);
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

