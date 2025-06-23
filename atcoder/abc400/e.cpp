// Problem: E - Ringo's Favorite Numbers 3
// Contest: AtCoder Beginner Contest 400
// URL: https://atcoder.jp/contests/abc400/tasks/abc400_e
// Time Limit: 2000
// Start: Tue Jun  3 18:33:13 2025
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

vector<int> primes() {
    vector<bool> p(1e6+5, false);
    vector<int> res;
    for(int i = 2; i < sz(p); i++) {
        if(!p[i]) {
            p[i] = true;
            res.pb(i);
            for(int j = i * i; j < sz(p); j+=i) {
                p[j] = true;
            }
        }
    }
    return res;
}
void shiina_mashiro() {
    int que; cin >> que;
    auto prime = primes();
    vector<int> gen;
    int MX = 1e12;
    for(int i = 0; i < sz(prime); i++) {
        int p = prime[i];
        for(int j = i+1; j < sz(prime); j++) {
            int q = prime[j];
            if((__int128)p * p * q * q > MX) break;

            __int128 x = p * p;
            while(x <= MX) {
                __int128 y = q * q;
                while((__int128)x * y <= MX) {
                    gen.emplace_back((int)x * y);
                    y = y * q * q;
                }
                x = x * p * p;
            }
        }
    }
    sort_unique(gen);
    for(;que--;) {
        int a; cin >> a;
        cout << *prev(upper_bound(all(gen), a)) << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

