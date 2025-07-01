// Problem: Monsters
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1194
// Time Limit: 1000
// Start: Sun Jun 22 03:39:49 2025
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
    int n, m; cin >> n >> m;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    
    auto win = [&](int x, int y) -> bool {
        if(x == 0 || y == 0 || x == n-1 || y == m-1) return true;
        return false;
    };

    queue<ar<int, 3>> bfs1, bfs2;
    int st = 0;
    vector<vector<int>> distM(n, vector<int>(m, 1e9)), distA(n, vector<int>(m, 1e9));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(vi[i][j] == 'A') {
            st = i*m+j;
            if(win(i, j)) {
                cout << "YES" << nl;
                cout << 0 << nl;
                return;
            } else {
                bfs1.push({0, i, j}); //push id
                distA[i][j] = 0;
            }
        }
        if(vi[i][j] == 'M') {
            bfs2.push({0, i, j});
            distM[i][j] = 0;
        }
    }
    pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    string s = "RDLU";
    bool ok = 0;
    auto bfs = [&](auto&dist, auto&q, int type) {
        vector<pair<int, char>> par(n*m);
        while(!q.empty()) {
            auto [d, x, y] = q.front(); q.pop();
            if(type && win(x, y) && dist[x][y] < distM[x][y]) {
                vector<char> path;
                for(int now = x * m + y; now != st; now = par[now].first) {
                    path.pb(par[now].second);
                }
                cout << "YES" << nl;
                cout << sz(path) << nl;
                for(auto &c : path | views::reverse) {
                    cout << c;
                }
                ok = 1;
                return;
            }
            for(int i = 0; i < 4; i++) {
                int nx = dirs[i].first + x;
                int ny = dirs[i].second + y;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || vi[nx][ny] == '#') continue;
                if(ckmin(dist[nx][ny], d + 1)) {
                    if(type) par[nx * m + ny] = {x * m + y, s[i]};
                    q.push({d + 1, nx, ny});
                }
            }
        }
    };
    bfs(distM, bfs2, 0);
    bfs(distA, bfs1, 1);
    if(!ok) cout << "NO" << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

