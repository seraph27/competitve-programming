// Problem: F - Random Gathering
// Contest: AtCoder Beginner Contest 417
// URL: https://atcoder.jp/contests/abc417/tasks/abc417_f
// Time Limit: 3000
// Start: Thu Aug 14 17:30:26 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <atcoder/lazysegtree>
#include <atcoder/modint>
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

using mint = atcoder::modint998244353;
const char nl = '\n';

struct S {
    mint a;
    int len;
};

struct F {
    bool lazy;
    mint v;
};

int ID = (1LL << 61);

S op(S a, S b) {
    return {a.a + b.a, a.len + b.len};
}

S e() {
    return {mint(0), 0};
}

S mapping(F l, S x) {
    if(!l.lazy) return x;
    return {l.v * x.len, x.len};
}

F composition(F f, F g) {
    if(!f.lazy) return g;
    return f;
}

F id() { return {false, mint(0)};}

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<S> vi(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vi[i] = {mint(x), 1};
    }

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(vi);

    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        --l;
        S res = seg.prod(l, r);
        mint tot = res.a;
        debug(tot.val());

        int L = res.len;
        debug(L);
        seg.apply(l, r, {true, tot * mint(L).inv()});
    }

    for(int i = 0; i < n; i++) {
        cout << seg.get(i).a.val() << " ";
    }
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

