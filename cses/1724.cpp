// Problem: Graph Paths II
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1724
// Time Limit: 1000
// Start: Thu Jul 31 15:44:32 2025
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

struct matrix{
    int n;
    vector<vector<int>> mat;

    matrix(int siz, bool id = false) : n(siz), mat(siz, vector<int>(siz, 3e18)) {
        if(id) {
            for(int i = 0; i < n; i++) mat[i][i] = 0;
        }
    }

    void add(int a, int b, int c) {
        ckmin(mat[a][b], c);
    }

    matrix operator*(const matrix &rhs) const {
        matrix res(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                __int128 acc = 3e18;
                for (int k = 0; k < n; ++k) {
                    ckmin(acc, __int128(mat[i][k]) + rhs.mat[k][j]);
                }
                res.mat[i][j] = acc;
            }
        }
        return res;
    }

    void exp(int p) {
        matrix res(n, true);
        matrix base = *this;
        while(p > 0) {
            if(p & 1) res = res * base;
            base = base * base;
            p >>=1;
        }
        mat = std::move(res.mat);
    }
};

void shiina_mashiro() {
    int n, m, k; cin >> n >> m >> k;
    
    matrix M(n);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        M.add(a, b, c);
    }

    M.exp(k);
    auto get = M.mat[0][n-1];
    cout << (get > 2e18 ? -1 : get) << nl;
    
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

