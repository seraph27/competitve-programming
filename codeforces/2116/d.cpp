// Problem: D. Gellyfish and Camellia Japonica
// Contest: Codeforces Round 1028 (Div. 2)
// URL: https://codeforces.com/contest/2116/problem/D
// Time Limit: 2000
// Start: Sat May 31 10:09:24 2025
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
    int n, q; cin >> n >> q;
    vector<int> b(n);
    for(auto &x : b) cin >> x;
    
    vector<ar<int, 3>> queries(q);
    vector<int> state(n);
    iota(all(state), 0);
    vector<vector<int>> tree;
    tree.resize(n);
    int k = n;
    for(int i = 0; i < q; i++) {
        int x, y, z; cin >> x >> y >> z;
        --x;--y;--z;
        queries[i] = {x, y, z};
        tree.pb({state[x], state[y]});
        state[z] = k++;
    }
    debug(tree);
    vector<int> req(n + q, 0);
    for(int i = 0; i < n; i++) {
        req[state[i]] = b[i];
    }

    for(int i = n + q - 1; i >= 0; i--) {
        for(auto child : tree[i]) {
            ckmax(req[child], req[i]);
        }
    }
    
    vector<int> ans(req.begin(), req.begin() + n);
    auto tmp = ans;
    for(auto [x, y, z] : queries) {
        tmp[z] = min(tmp[x], tmp[y]);
    }
    if(tmp != b) {
        cout << -1 << nl;
        return;
    }
    for(auto x : ans) cout << x << " ";
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

