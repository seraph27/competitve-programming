// Problem: D. Igor In the Museum
// Contest: Educational Codeforces Round 1
// URL: https://codeforces.com/contest/598/problem/D
// Time Limit: 1000
// Start: Mon Jun  9 16:50:14 2025
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
    int n, m, q; cin >> n >> m >> q;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i];
    }

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> id(n*m, 0);
    
    pii dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int sum = 0;
    auto dfs = [&](auto&&s, int x, int y, int idd) -> void {
        vis[x][y] = idd;
        for (auto &[dx, dy] : dirs) {
            int nx = dx + x, ny = dy + y;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            if(vi[nx][ny] == '*') {
                debug(sum);
                sum++;
                continue;
            }
            s(s, nx, ny, idd);
        }
    };
    int k = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && vi[i][j] == '.') {
                sum = 0;
                dfs(dfs, i, j, k);
                debug(vis);
                id[k] = sum;
                k++;
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        --x; --y;
        cout << id[vis[x][y]] << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

