// Problem: G. Nastiness of Segments
// Contest: Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/contest/2184/problem/G
// Time Limit: 3000
// Start: Mon Jan 12 07:55:12 2026
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
#define eb emplace_back
#define db double

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
    segtree(int siz, vector<int> &v) {
        n = siz;
        t.assign(2 * n, 4e18);
        for(int i = 0; i < n; i++) t[n + i] = v[i];
        for(int i = n-1; i>0; i--) t[i] = min(t[i<<1], t[i<<1|1]);
    }

    void update(int p, int val) {
        for(t[p+=n] = val; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
    }

    //[l, r)
    int query(int l, int r) {
        int res = 4e18;
        ckmin(r, n);
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) ckmin(res, t[l++]);
            if(r&1) ckmin(res, t[--r]);
        }
        return res;
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    segtree seg(n, vi);

    for(;q--;) {
        int type; cin >> type;
        if(type == 1) {
            int idx, val; cin >> idx >> val;
            seg.update(--idx, val);
        } else {
            int l, r; cin >> l >> r;
            --l; --r;
            int L = 0, R = r - l, ans = L;

            while(L <= R) {
                int mid = (L + R) >> 1;
                if(seg.query(l, l + mid + 1) >= mid) {
                    L = mid + 1, ans = mid;
                } else {
                    R = mid - 1;
                }
            }
            if(seg.query(l, l + ans + 1) == ans) {
                cout << 1 << nl;
            } else {
                cout << 0 << nl;
            }
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

