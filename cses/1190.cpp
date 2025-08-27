// Problem: Subarray Sum Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1190
// Time Limit: 1000
// Start: Thu Aug 21 20:51:36 2025
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

struct Node {
    int sum, L, R, max;
    bool full;
};

Node make(int x) {
    return {x, x, x, x, 1};
}

Node combine(Node a, Node b) {
    Node res;
    res.sum = a.sum + b.sum;
    res.L = max(a.L, a.full ? a.sum + b.L : (int)-4e18);
    res.R = max(b.R, b.full ? a.R + b.sum : (int)-4e18);
    res.max = max({a.max, b.max, a.R + b.L});
    res.full = a.full && b.full;
    return res;
}

struct segtree {
    int n; vector<Node> tr;
    
    segtree(int N) {
        n = 1;
        while(n < N) n <<= 1;
        tr.assign(2 * n, {0, 0, 0, 0, 1});
    }

    void build(vector<int> &v) {
        for(int i = 0; i < sz(v); i++) tr[i + n] = make(v[i]);
        for(int i = n-1; i > 0; i--) tr[i] = combine(tr[i << 1], tr[i << 1 | 1]);
    }

    void update(int p, int x) {
        p += n;
        tr[p] = make(x);
        for(p >>= 1; p ; p >>= 1) tr[p] = combine(tr[p << 1], tr[p << 1 | 1]);
    }

    Node query(int l, int r) {
        Node L = make(0), R = make(0);
        for(l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if(l & 1) L = combine(L, tr[l++]);
            if(!(r & 1)) R = combine(tr[r--], R);
        }
        return combine(L, R);
    }
};
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    segtree seg(n);
    seg.build(vi);
    for(int i = 0; i < m; i++) {
        int k, x; cin >> k >> x;
        seg.update(--k, x);
        cout << seg.query(0, n-1).max << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

