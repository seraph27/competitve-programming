// Problem: E - LCM Sequence
// Contest: AtCoder Beginner Contest 412
// URL: https://atcoder.jp/contests/abc412/tasks/abc412_e
// Time Limit: 4000
// Start: Thu Jul  3 01:27:28 2025
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

template <int N>
struct sieve {
    vector<int> primes;
    array<int, N+1> spf;
    sieve() : spf() {
        for (int i = 2; i <= N; i++) {
            if (!spf[i]) {
                spf[i] = i;
                primes.push_back(i);
            }
            for (int j = 0; i * primes[j] <= N; j++) {
                spf[i*primes[j]] = primes[j];
                if (primes[j] == spf[i]) break;
            }
        }
    }
    bool prime(int x) const {
        return spf[x] == x;
    }
    vector<int> facs(int x) const {
        vector<int> ret;
        while (x != 1) {
            ret.push_back(spf[x]);
            x /= spf[x];
        }
        return ret;
    }
    vector<array<int, 2>> facs2(int x) const {
        vector<array<int, 2>> ret;
        while (x != 1) {
            if (!ret.empty() && ret.back()[0] == spf[x]) ret.back()[1]++;
            else ret.push_back({spf[x], 1});
            x /= spf[x];
        }
        return ret;
    }
    vector<int> divs(int x) const {
        vector<int> divisors(1, 1);
        while (x > 1) {
            int p = spf[x], c = 0;
            while (x % p == 0) x /= p, c++;
            int sz = divisors.size();
            divisors.reserve(sz*(c+1));
            for (int i = 1, pw = p; i <= c; i++, pw *= p) {
                for (int j = 0; j < sz; j++) {
                    divisors.push_back(divisors[j] * pw);
                }
            }
        }
        return divisors;
    }
};

sieve<10000500> S;
void shiina_mashiro() {
    int L, R; cin >> L >> R;
    vector<int> vis(R-L+1);
    int ans = 0;
    for(auto &p : S.primes) {
        for (int k = (L+p-1)/p*p; k <= R; k+=p) {
            if(k==L) continue;
            if(vis[k - L]) continue;
            vis[k - L] = 1;
            int y = k;
            while(y%p == 0) y/=p;
            if(y == 1) ans++;
        }
    }
    ans += count(all(vis), 0);
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

