// Problem: F - Athletic
// Contest: AtCoder Beginner Contest 408
// URL: https://atcoder.jp/contests/abc408/tasks/abc408_f
// Time Limit: 2000
// Start: Sat Aug 16 16:14:14 2025
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

struct segtree {
    int n; vector<int> t;
    segtree(int siz) {
        n = siz;
        t.assign(2 * n, 0);
        for(int i = n-1; i>0; i--) t[i] = max(t[i<<1], t[i<<1|1]);
    }

    void update(int p, int val) {
        for(t[p+=n] = val; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
    }

    int query(int l, int r) {
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) ckmax(res, t[l++]);
            if(r&1) ckmax(res, t[--r]);
        }
        return res;
    }
};

void shiina_mashiro() {
    int n, d, r; cin >> n >> d >> r;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        pos[x] = i;
    } 

    segtree seg(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) {
        if(i - d >= 0) seg.update(pos[i-d], dp[i-d] + 1); 
        int p = pos[i];
        int L = max(0LL, p - r), R = min(n, p + r + 1);
        int mx = seg.query(L, R);
        ckmax(dp[i], mx);
    }
    cout << *max_element(all(dp)) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

