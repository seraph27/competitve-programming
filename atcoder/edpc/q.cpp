// Problem: Q - Flowers
// Contest: Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_q
// Time Limit: 2000
// Start: Thu May 14 00:07:19 2026
// atcoder
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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

using mint = modint998244353;
const char nl = '\n';

struct segtree {
    int siz; 
    vector<int> tr;

    segtree(int n) : siz(n), tr(2 * n) {};
    
    void assign(int p, int val) {
        p += siz;
        for(tr[p] = val; p > 1; p >>= 1) {
            ckmax(tr[p>>1], max(tr[p], tr[p ^ 1]));
        }
    }

    int query(int l, int r) {
        int mx = -4e18;
        for(l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
            if(l&1) ckmax(mx, tr[l++]);
            if(r&1) ckmax(mx, tr[--r]);
        } 
        return mx;
    }
};

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> h(n), vi(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> vi[i];

    //dp[i][j] := maximum sum at ith flower where last height is j

    // next flower if >= j pick or no pick
    // if < j, no pick only 
    //
    //
    int mx = *max_element(all(h));
    segtree dp(mx + 1);
    dp.assign(h[0], vi[0]);
    for(int i = 1; i < n; i++) {
        auto lst = dp.query(0, h[i]);
        dp.assign(h[i], lst + vi[i]);
    }
    cout << dp.query(0, mx + 1) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
