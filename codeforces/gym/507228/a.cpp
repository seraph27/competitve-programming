// Problem: A. Mixologist - Extreme
// Contest: Mixologist-Ex
// URL: https://codeforces.com/gym/507228/problem/A
// Time Limit: 4000
// Start: Wed Jul  2 04:56:55 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
#define ll long long
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
    vector<int> vi(m);
    for(int i = 0; i < m; i++) cin >> vi[i];
    
    /*
    //O(nm)
    vector<mint> dp(n+1, 0), dp2(n+1, 0), pref(n+2, 0);
    dp[0] = 1;
    for(int k = 0; k < m; k++) {
        pref[0] = 0;
        for(int i = 0; i <= n; i++) {
            pref[i+1] = pref[i] + dp[i];
        }
        for(int i = 0; i <= n; i++) {
            int L = max(0, i - vi[k]);
            dp2[i] = pref[i+1] - pref[L];
        }
        swap(dp, dp2);
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i].v << " ";
    }
    */
    using mint = atcoder::modint998244353;
    using poly = vector<mint>;
    poly facs(m+n+5);
    facs[0] = facs[1] = 1;
    for(int i = 2; i < sz(facs); i++) facs[i] = facs[i-1] * i; 
    auto choose = [&](int n_, int k) {
        return facs[n_] * (facs[n_-k] * facs[k]).inv();
    };
    poly invD(n+1);
    for(int i = 0; i <= n; i++) {
        invD[i] = mint(-1).pow(m) * choose(m + i - 1, i);
    }
    sort(all(vi));
    auto cmp = [](pair<int, poly> const &a, pair<int, poly> const &b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, poly>, vector<pair<int, poly>>, decltype(cmp)> pq(cmp);
    auto make = [&](int siz) {
        int D = min(siz+1, n);
        poly r(D+1, 0);
        r[0] = -1;
        if(siz+1 <= n) r[siz+1] = 1;
        return r;
    };
    for(int a : vi) {
        auto P = make(a);
        pq.emplace(sz(P), move(P));
    }
    while(sz(pq) > 1) {
        auto [s1, A] = move(pq.top()); pq.pop();
        auto [s2, B] = move(pq.top()); pq.pop();
        poly C = atcoder::convolution(A, B);
        if(sz(C) > n+1) C.resize(n+1);
        pq.emplace(sz(C), C);
    }
    poly ans = move(pq.top().second);
    ans.resize(n+1);
    ans = atcoder::convolution(ans, invD);
    ans.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i].val() << " ";
    }
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

