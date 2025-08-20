// Problem: E - Hungry Takahashi
// Contest: Japan Registry Services (JPRS) Programming Contest 2025#2 (AtCoder Beginner Contest 415)
// URL: https://atcoder.jp/contests/abc415/tasks/abc415_e
// Time Limit: 3000
// Start: Fri Aug  8 18:45:16 2025
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
    int h, w; cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> grid[i][j];

    vector<int> cost(h + w - 1);
    for(int i = 0; i < h + w - 1; i++) cin >> cost[i];

    auto f = [&](int i, int j) { return cost[i + j] - grid[i][j]; };
    auto ok = [&](int m) -> bool {
        vector<int> best(h * w, 4e18);
        auto id = [&](int x, int y) { return x * w + y;  };
        best[id(0, 0)] = f(0, 0);
        if(best[id(0, 0)] > m) return false;

        for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
            int cur = best[id(i, j)];
            if(cur > m) continue;
            if(i + 1 < h) {
                int nw = cur + f(i + 1, j);
                if(nw <= m) ckmin(best[id(i + 1, j)], nw);
            }
            if(j + 1 < w) {
                int nw = cur + f(i, j + 1);
                if(nw <= m) ckmin(best[id(i, j + 1)], nw);
            }
        }
        return best[id(h - 1, w - 1)] <= m;
    };
    int l = 0, r = 1e15, ans = l; 
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(ok(mid)) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

