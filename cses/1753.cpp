// Problem: String Matching
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1753
// Time Limit: 1000
// Start: Thu Jul 24 17:36:56 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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

const int hash_mod = 1e9+7;
int binpow(int a, int b) {
    int r = 1;
    for (; b > 0; b >>= 1, a = (long long)a*a%hash_mod) if (b&1) r = (long long)r*a%hash_mod;
    return r;
}
const int b_N = 2;
bool init_ = 0;
array<int, b_N> bases;
void init() {
    for (int i = 0; i < b_N; i++) {
        bases[i] = rint(2, hash_mod-1);
    }
}
template<typename T> struct Hash {
    array<vector<int>, b_N> pref, inv;
    Hash(const T& s) {
        if (!init_) init(), init_ = 1;
        int n = s.size();
        for (int i = 0; i < b_N; i++) {
            pref[i].resize(n), inv[i].resize(n);
            inv[i][n-1] = binpow(binpow(bases[i], n-1), hash_mod-2);
            for (int j = n-2; j >= 0; j--) inv[i][j] = (long long)inv[i][j+1] * bases[i] % hash_mod;
            for (int j = 0, b = 1; j < n; j++, b = (long long)b * bases[i] % hash_mod) {
                pref[i][j] = (j?pref[i][j-1]:0) + (long long)b*(int(s[j])+2)%hash_mod;
                if (pref[i][j] >= hash_mod) pref[i][j] -= hash_mod;
            }
        }
    }
    array<int, b_N> query(int l, int r) const {
        array<int, b_N> ret;
        for (int i = 0; i < b_N; i++) {
            ret[i] = pref[i][r] - (l?pref[i][l-1]:0);
            if (ret[i] < 0) ret[i] += hash_mod;
            ret[i] = (long long)ret[i] * inv[i][l] % hash_mod;
        }
        return ret;
    }
};
void shiina_mashiro() {
    string s, t; cin >> s >> t;
    Hash h1(s), h2(t);
    int ans = 0;
    for(int i = 0; i < sz(s) - sz(t) + 1; i++) {
        if(h2.query(0, sz(t)-1) == h1.query(i, i + sz(t)-1)) ans++;
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

