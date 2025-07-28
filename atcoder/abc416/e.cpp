// Problem: E - Development
// Contest: AtCoder Beginner Contest 416
// URL: https://atcoder.jp/contests/abc416/tasks/abc416_e
// Time Limit: 3500
// Start: Sat Jul 26 20:32:52 2025
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

    int dist[500][500]{};
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < 500; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        ckmin(dist[a][b], c);
        ckmin(dist[b][a], c);
    }

    int k, T; cin >> k >> T;

    vector<int> air(k);
    for(int i = 0; i < k; i++) {
        cin>>air[i];
        --air[i];
    }
    for(int i = 0; i < k; i++) for(int j = i+1; j < k; j++) {
        ckmin(dist[air[i]][air[j]], T);
        ckmin(dist[air[j]][air[i]], T);
    }
    for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ckmin(dist[i][j], dist[i][k] + dist[k][j]);

    int q; cin >> q;
    for(;q--;) {
        int type; cin >> type;
        if(type == 1) {
            int x, y, t; cin >> x >> y >> t;
            --x; --y;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
                ckmin(dist[i][j], min(dist[i][x] + dist[y][j] + t, dist[i][y] + dist[j][x] + t));
            }
        } else if(type == 2) {
            int x; cin >> x;
            --x;
            air.pb(x);
            vector<int> mx(n, 4e18);
            for(auto&a : air) for(int i = 0; i < n; i++) ckmin(mx[i], dist[i][a]);
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ckmin(dist[i][j], mx[i]+mx[j]+T);
        } else{
            int ans = 0;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(dist[i][j] < 1e18) ans += dist[i][j];
            cout << ans << nl;
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

