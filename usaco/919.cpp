// Problem: Problem 2. Painting the Barn
// Contest: USACO 2019 February Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=919
// Time Limit: 4000
// Start: Wed Jun  4 18:34:19 2025
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
    int n, k; cin >> n >> k;
    vector<vector<int>> pref(1005, vector<int>(1005, 0));
    auto add = [&](int x1, int y1, int x2, int y2) {
        pref[x1][y1]++;
        pref[x2][y1]--;
        pref[x1][y2]--;
        pref[x2][y2]++;
    };

    for(int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        add(a, b, c, d);
    }

    for(int i = 0; i <= 1001; i++) {
        for(int j = 0; j <= 1001; j++) {
            pref[i][j+1] += pref[i][j];
        }
    }
    for(int j = 0; j <= 1001; j++) {
        for(int i = 0; i <= 1001; i++) {
            pref[i+1][j] += pref[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i <= 1001; i++) for(int j = 0; j <= 1001; j++) {
        if(pref[i][j] == k) {
            ans++;
        }
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("paintbarn.in","r",stdin); freopen("paintbarn.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

