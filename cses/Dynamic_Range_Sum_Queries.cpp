// Problem: Dynamic Range Sum Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1648
// Time Limit: 1000
// Start: 2024/09/09 22:33:06

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

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    fenwick<ll> fw(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        fw.update(i, x);
    }
    
    for(;q--;) {
        int type; cin >> type;
        debug(fw.query(0, 0));
        if(type == 1) {
            int p, x; cin >> p >> x;
            --p;
            fw.update(p, x - fw.query(p, p));
        } else{
            int l, r; cin >> l >> r;
            --l;--r;
            cout << fw.query(l, r) << nl;
        }
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

