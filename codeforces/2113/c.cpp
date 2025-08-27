// Problem: C. Smilo and Minecraft
// Contest: Codeforces Round 1031 (Div. 2)
// URL: https://codeforces.com/contest/2113/problem/C
// Time Limit: 2000
// Start: Sun Aug 24 20:55:13 2025
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
    int n, m, k; cin >> n >> m >> k;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    int gold = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(vi[i][j] == 'g') gold++;
        pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (vi[i][j] == 'g');
    }

    auto query = [&](int x1, int y1, int x2, int y2) -> int {
        return pref[x2][y2] - pref[x1][y2] - pref[x2][y1] + pref[x1][y1];
    };
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        if(vi[i][j] == '.') {
            int x1 = i - (k - 1);
            int y1 = j - (k - 1);
            int x2 = i + k - 1;
            int y2 = j + k - 1;
            auto sum = query(max(0LL, x1), max(0LL, y1), min(n, x2 + 1), min(m, y2 + 1));
            ckmax(ans, gold - sum);
        } 
    }
    cout << ans << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

