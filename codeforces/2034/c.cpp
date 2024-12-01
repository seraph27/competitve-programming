// Problem: C. Trapped in the Witch's Labyrinth
// Contest: Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/C
// Time Limit: 3000
// Start: 2024/11/30 6:53:49
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
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    int ans = 0;
    map<char, pair<int, int>> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    vector<vector<int>> vis(n, vector<int>(m)); //2 means can escape
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(grid[i][j] == '?') continue;
        auto dir = mp[grid[i][j]];
        if(i + dir.first < 0 || i + dir.first >= n || j + dir.second < 0 || j + dir.second >= m) {
            vis[i][j] = 2;
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(vis[i][j] || grid[i][j] == '?') continue;
        int y = i, x = j;
        vector<pair<int, int>> curr;
        while(true) {
            auto dir = mp[grid[y][x]];
            if(vis[y][x] == 2) {
                for(auto &[fi, se] : curr) vis[fi][se] = 2;
                vis[y][x] = 2;
                curr.clear();
                break;
            } else if(vis[y][x] == 1) {
                for(auto &[fi, se] : curr) vis[fi][se] = 1;
                vis[y][x] = 1;  
                curr.clear();
                break;
            } 
            int ny = y + dir.first, nx = x + dir.second;
            if(grid[ny][nx] == '?') break;
            curr.pb({y, x});
            vis[y][x] = 1;  
            y = ny, x = nx;
        }
    }
    debug(vis, ans);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(vis[i][j]!=2) {
            int ok = 0;
            for(auto &[c, p] : mp) {
                auto [dx, dy] = p;
                int x = j + dx, y = i + dy;
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(vis[y][x]!=2) {
                    ok = 1;
                    break;
                }
            }
            if(ok) ans++;
        }
    }
    debug(vis);
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        debug(t);
        shiina_mashiro();
    }
}

