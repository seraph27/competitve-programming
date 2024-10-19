// Problem: D - Chocolate Chip Fabrication
// Contest: ICPC practice contest
// URL: https://vjudge.net/contest/664971#problem/D
// Time Limit: 1000
// Start: Fri Oct 18 21:56:16 2024
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vi;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        a[i] = s;
        for(int j = 0; j < m; j++) {
            if(s[j]=='X') vi.pb({i, j});
        }
    }
    int ans = 0;
    pii dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while(sz(vi)) {
        vector<pair<int, int>> vi2;
        vector<pair<int, int>> bad;
        for(int i = sz(vi)-1; i >= 0; i--) {
            auto [x, y] = vi[i];
            bool ok = 1;
            for(auto [dx, dy]: dirs) {
                int nx = x+dx, ny = y+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m || a[nx][ny]=='-') ok = 0;
            }
            if(ok) vi2.pb(vi[i]);
            else bad.pb(vi[i]);
        }
        for(auto [x, y]: bad) a[x][y] = '-';
        vi = vi2;
        ans++;
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

