// Problem: P1379 八数码难题
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P1379
// Time Limit: 1000
// Start: Wed Aug 27 21:07:30 2025
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
    string s; cin >> s;
    string t = "123804765";

    queue<pair<string, int>> bfs;

    pii dirs[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    unordered_set<string> st;
    bfs.push({s, 0});

    while(!bfs.empty()) {
        auto [f, dis] = bfs.front(); bfs.pop();
        if(f == t) {
            cout << dis << nl;
            return;
        }

        ar<ar<int, 3>, 3> grid;
        for(int i = 0; i < 9; i++) grid[i/3][i%3] = f[i] - '0';
        int x, y;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) if(grid[i][j] == 0) x = i, y = j;
        for(auto&[dx, dy] : dirs) {
            int nx = dx + x, ny = dy + y;
            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            swap(grid[x][y], grid[nx][ny]);
            string ns;
            for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) ns.pb('0' + grid[i][j]);
            if(!st.count(ns)) {
                bfs.push({ns, dis + 1});
                st.insert(ns);
            }
            swap(grid[x][y], grid[nx][ny]);
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

