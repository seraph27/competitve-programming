// Problem: E. Anya and Cubes
// Contest: Codeforces Round 297 (Div. 2)
// URL: https://codeforces.com/problemset/problem/525/E
// Time Limit: 2000
// Start: Tue Aug 26 08:42:55 2025
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
    int n, k, s; cin >> n >> k >> s;
    vector<int> cube(n);
    for(int i = 0; i < n; i++) cin >> cube[i];
    const int LIM = 18;
    vector<int> pref(18);
    iota(all(pref), 1);
    for(int i = 0; i < LIM - 1; i++) pref[i + 1] *= pref[i]; 
    int ans = 0;

    auto f = [&](vector<int> &v) {
        int siz = sz(v);
        vector<vector<int>> dp(k + 1);
        int facmask = 0;
        for(int i = 0; i < siz; i++) if(v[i] <= LIM && pref[v[i] - 1] <= s) facmask |= (1 << i);
        for(int msk = 0; msk < 1 << siz; msk++) {
            auto left = msk & facmask;
            for(int sub = left; ; sub = (sub-1) & left) {
                int sum = 0;
                for(int i = 0; i < siz; i++) {
                    if((msk & sub) >> i & 1) {
                        sum += pref[v[i] - 1];
                    } else if(msk >> i & 1) {
                        sum += v[i];
                    }
                    if(sum > s) break;
                }
                if(sum <= s) {
                    auto used = __builtin_popcount(msk & sub);
                    if(used <= k) {
                        dp[used].pb(sum);
                    }
                }
                if(sub==0)break;
            }
        }
        return dp;
    };
    int mid = n / 2;
    vector<int> L(cube.begin(), cube.begin() + mid), R(cube.begin() + mid, cube.end());
    auto h1 = f(L);
    auto h2 = f(R);
    debug(h1, h2);
    for(auto&x : h1) sort(all(x));
    for(auto&x : h2) sort(all(x));
    for(int b1 = 0; b1 <= k; b1++) {
        for(auto&x : h1[b1]) {
            for(int b2 = min(sz(h2) - 1, k - b1); b2 >= 0; b2--) {
                auto lb = lower_bound(all(h2[b2]), s - x) - h2[b2].begin();
                auto rb = upper_bound(all(h2[b2]), s - x) - h2[b2].begin();
                ans += rb - lb; 
            }
        }
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

