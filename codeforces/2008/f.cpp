// Problem: F. Sakurako's Box
// Contest: Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/F
// Time Limit: 2000
// Start: 2024/09/01 22:41:43

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
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
const int INF = 0x3f3f3f3f;

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

void shiina_mashiro() {
    int n; cin >> n;
    vector<ll> vi(n);
    for(auto&a: vi) cin >> a;
    ll sum = accumulate(all(vi), 0LL);
    
    mint ans = 0;
    
    for(int i = 0; i < n; i++) {
        mint left = sum-vi[i];
        ans += left * (ll)vi[i];
    }


    ll div = (ll)n*(n-1)/2;
    ans/=2;

    cout << ans * ((mint)div).inv() << nl; 
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}