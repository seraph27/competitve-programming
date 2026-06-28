// Problem: R - Walk
// Contest: Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_r
// Time Limit: 2000
// Start: Fri May 15 14:52:30 2026
// atcoder
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/modint>

#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using namespace atcoder;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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

using mint = modint1000000007;
const char nl = '\n';

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
    matrix pow(long long e) const {
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

struct Add { 
    mint operator() (mint x, mint y) const { return x + y; } 
};

struct Mul {
    mint operator() (mint x, mint y) const { return x * y; }
};
void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<vector<int>> vi(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n ; j++) cin >> vi[i][j];

    Add add_op{};
    Mul mul_op{};
    matrix<mint, Add, Mul> mat(n, add_op, mul_op, (mint)0, (mint)1);

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        if(vi[i][j]) mat(i, j) = 1;
    }
    
    auto get = mat.pow(k);

    mint ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ans += get(i, j);
    cout << ans.val() << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
