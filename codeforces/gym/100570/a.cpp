// Problem: A. LCM Query
// Contest: Hello 2015 (Div.1)
// URL: https://codeforces.com/gym/100570/problem/A
// Time Limit: 4000
// Start: Sat Aug  2 16:56:15 2025
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

template<typename it, typename bin_op>
struct sparse_table {
    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op F;
 
    sparse_table(it first, it last, bin_op op) : t(1), F(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < sz(t); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = F(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }
 
    T query(int l, int r) {
        int h = 31 - __builtin_clz(r-l+1);
        return F(t[h][l], t[h][r-(1<<h)+1]);
    }
};

template<class T> struct segtree {
    const int N; vector<T> tree;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N, numeric_limits<T>().max()) {}

    void update(int l, int r, T v) {
        r++;
        for(l += N, r += N; l < r; l>>=1, r>>=1) {
            if(l & 1) ckmin(tree[l++], v);
            if(r & 1) ckmin(tree[--r], v);
        }
    }

    T query(int p) {
        T res = numeric_limits<T>().max();
        for(p += N; p > 0; p>>=1) {
            ckmin(res, tree[p]);
        }
        return res;
    }
};

sieve<60> S;
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    
    auto p = S.primes;
    auto get = [&](int x) -> int {return lower_bound(all(p), x) - p.begin();};

    int MX = sz(p);
    
    vector<vector<ar<int, 2>>> facs(61);
    for(int i = 1; i <= 60; i++) facs[i] = S.facs2(i);
    vector<vector<int>> cnt(MX, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(auto &f : facs[vi[i]]) {
            auto a = f[0], c = f[1];
            cnt[get(a)][i] = c;
        }
    }
    auto mx = [](int a, int b) {return max(a, b);};
    vector<sparse_table<vector<int>::iterator, decltype(mx)>> st;
    st.reserve(MX);
    for(int i = 0; i < MX; i++) {
        st.emplace_back(all(cnt[i]), mx);
    }

    segtree<__int128> seg(n);
    vector<vector<ar<int, 3>>> change(n);
    for(int i = 0; i < n; i++) {
        __int128 sum = vi[i];
        int idx = i;
        while(idx < n) {
            int l = idx, r = n-1, ans = l; 
            __int128 best = 1;
            int tmp = idx;
            while(l<=r) {
                __int128 sum2 = 1;
                int mid = (l + r) >> 1;
                for(auto pp : p) {
                    auto id = get(pp);
                    auto res = st[id].query(i, mid);
                    for(int k = 0; k < res; k++) sum2 *= pp;
                }
                if(sum2 > sum) {
                    r = mid - 1, ans = mid, best = sum2;
                } else l = mid + 1;
            }
            debug(i, idx, tmp, ans, (int)sum, (int)best);
            if(ans == tmp) {
                seg.update(tmp-i, n-i-1, sum);
                break;
            }
            seg.update(tmp-i, ans-i-1, sum);
            sum = best;
            idx = ans;
        }
    }

    vector<int> V(n);
    const int mod = 1e9+7;
    for(int i = 0; i < n; i++) {
        V[i] = seg.query(i) % mod;
    }

    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        cout << V[--x] << '\n';
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

