// Problem: Grid Paths
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1625
// Time Limit: 1000
// Start: 2025/04/27 15:31:25
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

pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int ans = 0;
bool vis[7][7];
string s;
bool blocked(int x, int y) {
    if(x < 0 || x > 6 || y < 0 || y > 6) return true;
    return vis[x][y] ? true : false;    
}
void dfs(int x, int y, int moves) {
    if(moves==48 && x == 0 && y == 6) {
        ans++;
        return;
    }
    if(moves == 48) return;
    if(x==0 && y ==6 && moves < 48) return;
    bool up = blocked(x, y - 1);
    bool down = blocked(x, y + 1);
    bool left = blocked(x - 1, y);
    bool right = blocked(x + 1, y);
    if(up && down && !left && !right) return;
    if(left && right && !up && !down) return;

    vis[x][y] = 1;
    if(s[moves] == '?') {
        if(!up) dfs(x, y - 1, moves + 1);
        if(!down) dfs(x, y + 1, moves + 1);
        if(!left) dfs(x - 1, y, moves + 1);
        if(!right) dfs(x + 1, y, moves + 1);
    } else {
        int dx = 0, dy = 0;
        if(s[moves] == 'U') dy = -1;
        if(s[moves] == 'D') dy = 1;
        if(s[moves] == 'L') dx = -1;
        if(s[moves] == 'R') dx = 1;
        if(!blocked(x + dx, y + dy)) {
            dfs(x + dx, y + dy, moves + 1);
        }
    }
    vis[x][y] = 0;
}
void shiina_mashiro() {
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

