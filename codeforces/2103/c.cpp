// Problem: C. Median Splits
// Contest: Codeforces Round 1019 (Div. 2)
// URL: https://codeforces.com/contest/2103/problem/C
// Time Limit: 2000
// Start: Sat Aug 30 15:42:00 2025
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
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vi[i] = (x <= k ? 1 : -1);
    }
    vector<int> pref(n + 1), suf(n + 1);
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + vi[i];
    for(int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + vi[i];
    vector<int> prefmx(n + 1, -4e18), sufmx(n + 1, -4e18);
    for(int i = 1; i <= n; i++) prefmx[i] = max(prefmx[i - 1], pref[i]);
    for(int i = n - 1; i >= 0; i--) sufmx[i] = max(sufmx[i + 1], suf[i]);
    int ok = 0;
    for(int i = 0; i < n - 1; i++) {
        if(prefmx[i] >= 0 && sufmx[i + 1] >= 0) ok = 1;
    }
    int has = 4e18;
    for(int i = 0; i <= n - 1; i++) {
        if(i-1>=1 && pref[i-1] >= 0) ckmin(has, pref[i - 1]);
        if(pref[i] >= has) ok = 1;
    }
    debug(suf);
    int has2 = 4e18;
    for(int i = n; i >= 1; i--) {
        if(i+1 < n && suf[i+1] >= 0) ckmin(has2, suf[i + 1]);
        if(suf[i] >= has2) ok = 1;
    }

    cout << (ok ? "Yes" : "No") << nl;
    debug(prefmx, sufmx);
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

