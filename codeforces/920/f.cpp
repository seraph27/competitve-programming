// Problem: F. SUM and REPLACE
// Contest: Educational Codeforces Round 37 (Rated for Div. 2)
// URL: https://codeforces.com/contest/920/problem/F
// Time Limit: 2000
// Start: Sat May 24 00:26:49 2025
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

struct segs{
    int n; vector<int> tr;
    segs(int n) : n(n), tr(2*n, 0) {}
    void update(int pos, int val) {
        pos += n;
        tr[pos] = val;
        for(; pos > 1; pos >>= 1) tr[pos >> 1] = tr[pos] + tr[pos ^ 1];
    }
    int query(int l, int r) {
        l+=n; r+=n;
        int res = 0;
        for(; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res += tr[l++];
            if(r & 1) res += tr[--r];
        }
        return res;
    }
};

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    segs seg(n+1);
    int mx = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ckmax(mx, x);
        seg.update(i, x);
        if(x>2) s.insert(i);
    }

    auto div = [](int x) -> vector<int> {
        vector<int> res(x+1, 0);
        for(int d = 1; d <= x; d++) {
            for(int i = d; i <= x; i += d) {
                res[i]++;
            }
        }
        return res;
    };

    auto divs = div(mx);
    for(;m--;) {
        int t, l, r; cin >> t >> l >> r;
        if(t == 1) {
            l--; r--;
            vector<int> bad;
            for(auto it = s.lower_bound(l); it != s.end() && *it <= r; it++) {
                int now = seg.query(*it, *it + 1);
                int nd = divs[now];
                if(nd <= 2) bad.pb(*it);
                seg.update(*it, nd);
            }
            for(auto &x : bad) {
                s.erase(x);
            }
        } else {
            cout << seg.query(l - 1, r) << nl;
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

