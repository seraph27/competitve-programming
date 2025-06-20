// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
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
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    sort(all(vi));
    debug(vi);
    
    vector<int> med(n-k+1, 4e18);
    for(int i = 0; i < n-k+1; i++) {
        med[i] = vi[i+k/2];
    }
    vector<int> need(n-k+1), pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1] += pref[i] + vi[i];
    for(int i = 0; i < n-k+1; i++) {
        int half1 = (pref[i+k] - pref[i+k/2 + (k&1 ? 1 : 0)]) - (k/2) * med[i];
        int half2 = (pref[i+k/2] - pref[i]) - k/2 * med[i];
        need[i] = abs(half1) + abs(half2);
    }
    vector<int> L(n-k+1, 4e18), R(n-k+1, 4e18);
    L[0] = need[0];
    R[n-k] = need[n-k];
    for(int i = 1; i < sz(L); i++) {
        ckmin(L[i], min(L[i-1], need[i]));
    }
    for(int i = sz(R)-2; i>=0; i--) {
        ckmin(R[i], min(R[i+1], need[i]));
    }
    debug(need);
    debug(L, R);
    int ans = 4e18;
    for(int i = 0; i < sz(L); i++) {
        if(i+k < sz(R)) ckmin(ans, L[i] + R[i+k]);
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


