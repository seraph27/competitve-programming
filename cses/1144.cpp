// Problem: Salary Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1144
// Time Limit: 1000
// Start: Tue Jul 22 17:12:44 2025
// mintemplate
#include <algorithm>
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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};

//outside is all 0-indexed, inclusive, so [l, r]
//don't add 1 to update;

struct Z {
    char a;
    int b, c;
};
void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> salary(n);
    vector<int> ord;
    for(int i = 0; i < n; i++) {
        cin >> salary[i];
        ord.pb(salary[i]);
    }
    vector<Z> queries;
    for(int i = 0; i < q; i++) {
        char t; cin >> t;
        if(t == '!') {
            int k, x; cin >> k >> x;
            queries.pb({t, --k, x});
            ord.pb(x);
        } else {
            int a, b; cin >> a >> b;
            queries.pb({t, a, b});
        }
    }
    sort_unique(ord);

    auto get = [&](int x) -> int {
        return lower_bound(all(ord), x) - ord.begin();
    };
    
    fenwick<int> fw(sz(ord));
    for(int i = 0; i < n; i++) {
        fw.update(get(salary[i]), 1);
    }

    for(int i = 0; i < q; i++) {
        auto [t, a, b] = queries[i];
        debug(t);
        if(t == '!') {
            int old = salary[a];
            salary[a] = b;
            fw.update(get(old), -1);
            fw.update(get(b), 1);
        } else {
            int L = get(a), R = upper_bound(all(ord), b) - ord.begin() - 1;
            if(R < L) {
                cout << 0 << nl;
                continue;
            }
            cout << fw.query(L, R) << nl;
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

