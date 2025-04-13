// Problem: D - Santa Claus 2
// Contest: ユニークビジョンプログラミングコンテスト2024 クリスマス（AtCoder Beginner Contest 385）
// URL: https://atcoder.jp/contests/abc385/tasks/abc385_d
// Time Limit: 2000
// Start: 2025/01/11 13:25:36
// mintemplate
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

void shiina_mashiro() {
    int n, m, sx, sy; cin >> n >> m >> sx >> sy;
    map<int, set<int>> xy, yx;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        xy[x].insert(y);
        yx[y].insert(x);
    }
    set<ar<int, 2>> ans;
    for(int i = 0; i < m; i++) {
        char c; cin >> c;
        int d; cin >> d;
        set<ar<int, 2>> tmp;
        if(c =='U') {
            for(auto it = xy[sx].lower_bound(sy); it != xy[sx].end() && *it <= sy+d; it++) {
                tmp.insert({sx, *it});
            }
            sy += d;
        } else if(c == 'D') {
            for(auto it = xy[sx].lower_bound(sy-d); it != xy[sx].end() && *it <= sy; it++) {
                tmp.insert({sx, *it});
            }
            sy -= d;
        } else if(c == 'R') {
            for(auto it = yx[sy].lower_bound(sx); it != yx[sy].end() && *it <= sx+d; it++) {
                tmp.insert({*it, sy});
            }
            sx += d;
        } else {
            for(auto it = yx[sy].lower_bound(sx-d); it != yx[sy].end() && *it <= sx; it++) {
                tmp.insert({*it, sy});
            }
            sx -= d;
        }
        for(auto [x, y] : tmp) {
            ans.insert({x, y});
            xy[x].erase(y);
            yx[y].erase(x);
        }
    }
    debug(ans);
    cout << sx << " " << sy << " " << sz(ans) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

