// Problem: Next Prime
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/3396
// Time Limit: 1000
// Start: Thu Jul 24 14:15:53 2025
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

ll modmul(ll a, ll b, ll m) {
    __int128 r = (__int128)a*b;
    return (ll)(r % m);
}
ll modpow(ll a, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e&1) r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}
static const ll smallPrimes[] = {
    3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};
bool isPrime(ll n) {
    if (n < 2 || n%2==0) return n==2;
    for(ll p : smallPrimes) {
        if(n==p) return true;
        if(n%p == 0) return false;
    }
    ll d = n-1, s = 0;
    while ((d&1)==0) { d >>= 1; s++; }
    for (ll a : {2LL,325LL,9375LL,28178LL,450775LL,9780504LL,1795265022LL}) {
        if (a%n == 0) continue;
        ll x = modpow(a, d, n);
        if (x==1 || x==n-1) continue;
        bool comp = true;
        for (int r = 1; r < s; r++) {
            x = modmul(x, x, n);
            if (x == n-1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
ll next_prime(ll n) {
    if (n < 2) return 2;
    ll p = n+1 + (n&1);
    debug(p);
    while (!isPrime(p)) p += 2;
    return p;
}
void shiina_mashiro() {
    ll n; cin >> n;
    cout << next_prime(n) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

