// Problem: G. Farmer John's Last Wish
// Contest: Codeforces Round 1050 (Div. 4)
// URL: https://codeforces.com/contest/2148/problem/G
// Time Limit: 3000
// Start: Sun Sep 14 01:40:26 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

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

template <class T>
struct segtree {
    const int N; vector<T> tree;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N) {}
    void update(int pos, T x) {
        for (int i = pos+N; i > 0; i >>= 1) ckmax(tree[i], x);
    }
    T query(int node, int nl, int nr, int ql, int qr) {
        if (ql > nr || qr < nl) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return max(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};


sieve<(int)3e5+5> S;
void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&x : vi) cin >> x;
    int gd = vi[0];
    segtree<int> seg(n + 5);
    for(int i = 0; i < n; i++) {
        gd = gcd(gd, vi[i]);
        auto get = S.divs(vi[i]);
        for(auto&y : get) if(y != 1) seg.update(y, seg.query(y, y) + 1);
        cout << seg.query(gd + 1, n) << " ";
    }
    cout << '\n';
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

