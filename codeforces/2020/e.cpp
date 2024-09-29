// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
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
const int MOD = 1e9+7;
void shiina_mashiro() {
    set<int> s;
    int n; cin >> n;
    vector<int> a(n), p(n);
    for(auto&x: a) cin >> x;
    for(auto&a: p) cin >> a;
      long long expected_value = 0;
        
        // We process each bit position
        for (int bit = 0; bit < 10; ++bit) {
            long long prob_sum = 0; // Sum of probabilities for numbers with the current bit set
            long long prob_square_sum = 0; // Sum of squared probabilities for the current bit
            
            // Go through each element in the array
            for (int i = 0; i < n; ++i) {
                if (a[i] & (1 << bit)) {
                    // The i-th element has the current bit set
                    long long prob = p[i];
                    prob_sum = (prob_sum + prob) % MOD;
                    prob_square_sum = (prob_square_sum + (prob * prob) % MOD) % MOD;
                }
            }
            
            // Calculate contribution to the expected value from this bit
            long long contribution = (prob_sum * prob_sum % MOD - prob_square_sum + MOD) % MOD;
            contribution = (contribution * (1LL << (2 * bit)) % MOD) % MOD;
            expected_value = (expected_value + contribution) % MOD;
        }
        
        cout << expected_value << endl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}


