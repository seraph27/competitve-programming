// Problem: Permutation Rounds
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/3398
// Time Limit: 1000
// Start: Thu Jul 24 17:11:49 2025
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

sieve<(int)3e5> s;


template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;

    int v;

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }

    explicit operator int() const { return v; }
    explicit operator bool() const { return v; }

    friend ostream& operator << (ostream& out, const modnum& n) { return out << n.v; }
    friend istream& operator >> (istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = int((ll) v * o.v % MOD);
        return *this;
    }

    friend modnum binpow(modnum a, ll p) {
        if (p == 0) return 1;
        modnum ret = 1;
        for (; p; p /= 2, a *= a) if (p&1) ret *= a;
        return ret;
    }

    modnum inv() const {
        return binpow(*this, MOD-2);
    }
    friend modnum inv(const modnum& m) { return m.inv(); }

    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

const int mod = 1e9+7;
using mint = modnum<mod>;

vector<mint> facs, invfacs;

mint choose(int _a, int _b) {
    if (_b > _a || _a < 0 || _b < 0) return 0;
    return facs[_a] * invfacs[_b] * invfacs[_a-_b];
}

void finit(const int nx) {
    facs.resize(nx+1);
    invfacs.resize(nx+1);
    facs[0] = facs[1] = invfacs[0] = invfacs[1] = 1;
    for (int i = 2; i <= nx; i++) {
        facs[i] = facs[i-1] * mint(i);
    }
    invfacs[nx] = inv(facs[nx]);
    for (int i = nx-1; i > 1; i--) {
        invfacs[i] = invfacs[i+1] * mint(i+1);
    }
}

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n+1), vis(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> vi[i];
    vector<int> cyc;

    for(int i = 1; i < n; i++) {
        if(!vis[i]) {
            int cnt = 0;
            for(auto x = i; !vis[x]; vis[x] = 1, x = vi[x]) cnt++;
            cyc.pb(cnt);
        }
    }
    map<int, int> mp;
    for(auto&x : cyc) {
        auto sf = s.facs2(x);
        for(auto e : sf) {
            ckmax(mp[e[0]], e[1]);
        }
    }
    mint ans = 1;
    for(auto&[k, v] : mp) {
        ans *= binpow(mint(k), v);
    }
    cout << ans.v << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

