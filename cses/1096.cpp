// Problem: Throwing Dice
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1096
// Time Limit: 1000
// Start: Thu Jul 31 16:35:27 2025
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

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;

    int v;

    modnum() : v(0) {}
    modnum(int v_) : v(v_ % MOD) { if (v < 0) v += MOD; }

    explicit operator int() const { return v; }
    explicit operator bool() const { return v; }

    friend ostream& operator << (ostream& out, const modnum& n) { return out << n.v; }
    friend istream& operator >> (istream& in, modnum& n) { int v_; in >> v_; n = modnum(v_); return in; }

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
        v = v * o.v % MOD;
        return *this;
    }

    friend modnum binpow(modnum a, int p) {
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

    friend modnum operator ++ (modnum& a, int32_t) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int32_t) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

const int mod = 1e9+7;
using mint = modnum<mod>;

template<typename T, class Add, class Mul>
struct matrix {
    int n;
    vector<T> a;
    Add add;
    Mul mul;
    T add_id;
    T mul_id;
    matrix(int _n, Add _add, Mul _mul, T _add_id, T _mul_id)
        : n(_n), a(n * n), add(_add), mul(_mul), add_id(_add_id), mul_id(_mul_id) {}
    static matrix identity(int n, Add add, Mul mul, T add_id, T mul_id) {
        matrix m(n, add, mul, add_id, mul_id);
        for (int i = 0; i < n; ++i) m(i,i) = mul_id;
        return m;
    }
    T& operator()(int i, int j) { return a[i * n + j]; }
    T operator()(int i, int j) const { return a[i * n + j]; }
    matrix operator*(const matrix &rhs) const {
        matrix res(n, add, mul, add_id, mul_id);
        for (int i = 0; i < n * n; ++i) res.a[i] = add_id;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                T x = (*this)(i,k);
                for (int j = 0; j < n; ++j) {
                    res(i,j) = add(res(i,j), mul(x, rhs(k,j)));
                }
            }
        }
        return res;
    }
    matrix pow(int e) const {
        matrix base = *this;
        matrix res = identity(n, add, mul, add_id, mul_id);
        while (e > 0) {
            if (e & 1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
    vector<T> apply(const vector<T> &v) const {
        vector<T> out(n, add_id);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                out[i] = add(out[i], mul((*this)(i,j), v[j]));
            }
        }
        return out;
    }
};


void shiina_mashiro() {
    int n; cin >> n;
    if(n == 0){
        cout << 0 << nl;
        return;
    }
    if(n <= 6) {
        cout << (1 << (n-1)) << nl;
        return;
    }
    auto add = [](const auto &a, const auto &b) { return a + b; };
    auto mul = [](const auto &a, const auto &b) { return a * b; };
    matrix<mint, decltype(add), decltype(mul)> T(6, add, mul, mint(0), mint(1));
    for(int i = 0; i < 6; i++) T(0, i) = mint(1);
    for(int i = 1; i < 6; i++) T(i, i-1) = mint(1);

    auto P = T.pow(n-6);
    vector<mint> vi = {32, 16, 8, 4, 2, 1};

    auto ans = P.apply(vi);
    cout << ans[0].v << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

