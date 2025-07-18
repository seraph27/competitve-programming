// Problem: Knight's Tour
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1689
// Time Limit: 1000
// Start: Thu Jul 17 22:30:12 2025
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
    int x, y; cin >> x >> y;
    --x;--y;
    swap(x, y);

    vector<pii> moves;
    int vis[8][8]{};
    memset(vis, 0, sizeof vis);
    vis[x][y] = 1;
    moves.pb({x, y});

    pii dirs[8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    auto chk = [&](int xx, int yy) -> int {
        int cnt = 0;
        for(auto&[dx, dy] : dirs) {
            int nx = xx + dx, ny = yy + dy;
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || vis[nx][ny]) continue;
            cnt++;
        }
        return cnt;
    };
    auto dfs = [&](auto&&s, int xx, int yy, int move_cnt) -> bool {
        if(move_cnt == 64) return true;
        vector<pii> store;
        for(auto&[dx, dy] : dirs) {
            int nx = xx + dx, ny = yy + dy;
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || vis[nx][ny]) continue;
            store.pb({nx, ny});
        }
        sort(all(store), [&](const pii&a, const pii&b) {return chk(a.first, a.second) < chk(b.first, b.second);});
        for(auto&[nx, ny] : store) {
            vis[nx][ny] = 1;
            moves.emplace_back(nx, ny);
            if(s(s, nx, ny, move_cnt + 1)) return true;
            vis[nx][ny] = 0;
            moves.pop_back();
        }
        return false;
    };

    int ans[8][8]{};
    
    dfs(dfs, x, y, 1);
    assert(sz(moves) == 64);
    for(int i = 0; i < 64; i++) {
        ans[moves[i].first][moves[i].second] = i+1;
    }
    for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) {
        cout << ans[i][j] << " \n"[j==7];
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

