// Problem: E - Trapezium
// Contest: AtCoder Beginner Contest 418
// URL: https://atcoder.jp/contests/abc418/tasks/abc418_e
// Time Limit: 4000
// Start: Sat Aug  9 08:38:27 2025
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

struct Point {
    int x, y;
};


void shiina_mashiro() {
    int n; cin >> n;
    vector<Point> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i].x >> vi[i].y;

    auto slope = [&](Point a, Point b) -> pii{
        int dx = b.x - a.x, dy = b.y - a.y;
        int g = __gcd(llabs(dx), llabs(dy));
        dx /= g, dy /= g;
        if (dx < 0 || (dx == 0 && dy < 0)) dx = -dx, dy = -dy;
        return {dx, dy};
    };

    auto dist = [&](Point a, Point b) -> int{
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    };

    vector<pii> slopes, extra;

    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
        slopes.pb(slope(vi[i], vi[j]));
        extra.pb({vi[i].x + vi[j].x, vi[i].y + vi[j].y});
    }

    auto f = [&](vector<pii> &v) -> int {
        sort(all(v));
        int res = 0;
        for (int i = 0; i < sz(v); ) {
            int j = i;
            while (j < sz(v)&& v[j] == v[i]) j++;
            int c = j - i;
            res += c * (c - 1) / 2;
            i = j;
        }
        return res;
    };
    cout << f(slopes) - f(extra) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

