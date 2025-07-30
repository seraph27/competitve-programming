// Problem: Problem 1. Splitting the Field
// Contest: USACO 2016 US Open Contest, Gold
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=645
// Time Limit: 4000
// Start: Tue Jul 29 16:47:54 2025
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<pii> pts(n), pts2(n);

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
        pts2[i] = {y, x};
    }

    sort(all(pts));
    sort(all(pts2));
    int orig;
    auto f = [&](auto &points) -> int {
        int mnx = 4e18, mny = 4e18, mxx = 1, mxy = 1;
        for(auto&a : points) {
            ckmax(mxx, a.first);
            ckmax(mxy, a.second);
            ckmin(mnx, a.first);
            ckmin(mny, a.second);
        }
        debug(mxx, mxy, mnx, mny);
        int ans = (mxx-mnx) * (mxy-mny);
        orig = ans;
        multiset<int> y;
        for(auto&a: points) y.insert(a.second);
        debug(points);
        multiset<int> y2;
        int idx = 0;
        while(idx < n) {
            auto [fi, se] = points[idx];
            idx++;
            y2.insert(se);
            debug(y, y2, fi, se);
            y.erase(y.find(se));
            while(idx < n && points[idx].first == fi) {
                auto [_f, s] = points[idx];
                y2.insert(s);
                y.erase(y.find(s));
                idx++;
            }
            int nxtx = idx < n ? points[idx].first : mxx;
            int curry = sz(y2) ? *y2.rbegin() - *y2.begin() : 0;
            int nxty = sz(y) ? *y.rbegin() - *y.begin() : 0;
            ckmin(ans, (fi - mnx) * curry + (mxx - nxtx) * nxty);
        }
        return ans;
    };
    auto mn = min(f(pts), f(pts2));
    cout << orig - mn << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("split.in","r",stdin); freopen("split.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

