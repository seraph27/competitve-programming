// Problem: Minimal Grid Path
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/3359
// Time Limit: 1000
// Start: Wed May 14 21:56:38 2025
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<string> vi(n);
    for(auto&a: vi) cin >> a;
    string ans;
    vector<vector<int>> vis(n, vector<int>(n, 0)), vis2(n, vector<int>(n, 0));
    vis[0][0] = 1;
    ans.pb(vi[0][0]);
    for(int i = 1; i < n; i++) {
        int mn = 50;
        for(int k = i, j = 0; k >= 0; k--, j++) {
            if((k-1 >= 0 && vis[k-1][j]) || (j-1 >= 0 && vis[k][j-1])) {
                ckmin(mn, (int)vi[k][j] - 'A');
            }
        }
        for(int k = i, j = 0; k >= 0; k--, j++) {
            if((vi[k][j] - 'A' == mn) && ((k > 0 && vis[k-1][j]) || (j > 0 && vis[k][j-1]))) {
                vis2[k][j] = 1;
            } else {
                vis[k][j] = 1;
            }
        }
        ans.pb(char(mn + 'A'));
        swap(vis, vis2);
    }
    for(int j = 1; j < n; j++) {
        int mn = 50;
        for(int i = n-1, k = j; k < n; i--, k++) {
            if((i-1 >= 0 && vis[i-1][k]) || (k-1 >= 0 && vis[i][k-1])) {
                ckmin(mn, (int)vi[i][k] - 'A');
            }
        }
        for(int i = n-1, k = j; k < n; i--, k++) {
            if((vi[i][k] - 'A' == mn) && ((i > 0 && vis[i-1][k]) || (k > 0 && vis[i][k-1]))) {
                vis2[i][k] = 1;
            } else {
                vis[i][k] = 1;
            }
        }
        ans.pb(char(mn + 'A'));
        swap(vis, vis2);
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

