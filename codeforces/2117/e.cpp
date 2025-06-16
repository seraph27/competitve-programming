// Problem: E. Lost Soul
// Contest: Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/E
// Time Limit: 2000
// Start: Sun Jun  8 08:22:04 2025
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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(auto&x: a) cin >> x;
    for(auto&x: b) cin >> x;
    int ans = 0;
    map<int, pair<vector<int>, vector<int>>> mp;
    for(int i = 0; i < n; i++) {
        if(i%2==0) mp[a[i]].first.pb(i);
        else mp[a[i]].second.pb(i);
        if(i%2) mp[b[i]].first.pb(i);
        else mp[b[i]].second.pb(i);
    }
    for(auto &[k, v] : mp) {
        int f1 = -1, f2 = -1;
        if(sz(v.first)) f1 = *max_element(all(v.first));
        if(sz(v.second)) f2 = *max_element(all(v.second));
        ckmax(ans, min(f1, f2) + 1); 
        for(auto &x : v.first) {
            if(f1-x > 1) ckmax(ans, x+1);
        }
        for(auto&x : v.second) {
            if(f2-x > 1) ckmax(ans, x+1);
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

