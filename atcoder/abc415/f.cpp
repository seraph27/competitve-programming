// Problem: F - Max Combo
// Contest: Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415)
// URL: https://atcoder.jp/contests/abc415/tasks/abc415_f
// Time Limit: 4000
// Start: Sat Aug  9 07:41:51 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
using namespace atcoder;
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
    int left, right, mx;
    bool full;
    char lc, rc;
};

Node e() {
    return {0, 0, 0, false, '?', '?'};
}

Node op(Node a, Node b) {
    if(a.lc == '?') return b;
    if(b.lc == '?') return a;
    
    if(a.rc != b.lc) {
        return {a.left, b.right, max(a.mx, b.mx), 0, a.lc, b.rc};
    } else {
        int full = a.full && b.full;
        int left = a.left + (a.full ? b.left : 0);
        int right = b.right + (b.full ? a.right : 0);
        int mx = max({a.mx, b.mx, a.right + b.left});
        return {left, right, mx, full, a.lc, b.rc};
    }
}


void shiina_mashiro() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    
    auto f = [&](char c) -> Node {
        return {1, 1, 1, true, c, c};
    };
    
    segtree<Node, op, e> seg(n);
    for (int i = 0; i < n; i++) seg.set(i, f(s[i]));

    for(;q--;) {
        int type; cin >> type;
        if(type == 1) {
            int i; char c; cin >> i >> c; i--;
            seg.set(i, f(c));
        } else {
            int l, r; cin >> l >> r; l--;
            cout << seg.prod(l, r).mx << nl;
        }
    }

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

