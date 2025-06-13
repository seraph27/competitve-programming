// Problem: C. Heavy Intervals
// Contest: Test contest
// URL: https://codeforces.com/group/Xa9FknAMM5/contest/612668/problem/C
// Time Limit: 1000
// Start: 2025/05/28 9:09:20
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
template<typename T, size_t N>
static void __print(const T (&a)[N]) {cerr << '{';for (size_t i = 0; i < N; ++i) {if (i) cerr << ',';__print(a[i]);}cerr << '}';}
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
    vector<int> l(n), c(n);
    multiset<int> r;
    for(auto&a : l) cin >> a;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        r.insert(x);
    }
    for(auto&a : c) cin >> a;

    sort(all(l));
    sort(all(c));
    
    int ans = 0;
    vector<int> segs;
    for(int i = n-1; i>=0; i--) {
        auto it = r.lower_bound(l[i]);
        segs.pb(*it - l[i]);
        r.erase(it);
    }
    sort(all(segs), greater<int>());
    for(int i = 0; i < n; i++) {
        ans += segs[i] * c[i];
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

