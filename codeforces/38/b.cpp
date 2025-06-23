// Problem: B. Chess
// Contest: School Personal Contest #1 (Winter Computer School 2010/11) - Codeforces Beta Round 38 (ACM-ICPC Rules)
// URL: https://codeforces.com/contest/38/problem/B
// Time Limit: 2000
// Start: Sat Jun  7 01:05:38 2025
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
    vector<vector<int>> grid(8, vector<int>(8, 0));

    pii dirs[8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    char a, b, c, d; cin >> a >> b >> c >> d;
    int rr = a-'a', kr = c-'a';
    int rc = (b-'0')-1, kc = (d-'0')-1;
    grid[rr][rc] = 1;
    for(int i = 0; i < 8; i++) grid[rr][i] = 1;
    for(int i = 0; i < 8; i++) grid[i][rc] = 1;
    grid[kr][kc] = 1;
    for(auto [dx, dy] : dirs) {
        int nx = kr + dx;
        int ny = kc + dy;
        if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
        grid[nx][ny] = 1;
    }
    debug(grid);
    int ans = 0;
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) {
        if(!grid[i][j]) {
            int ok = 1;
            for(auto [dx, dy] : dirs) {
                int nx = i + dx;
                int ny = j + dy;
                if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
                if(nx == kr && ny == kc) ok = 0;
                if(nx == rr && ny == rc) ok = 0;
            }
            if(ok) ans++;
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

