// Problem: Dynamic Range Minimum Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1649
// Time Limit: 1000
// Start: 2024/09/09 23:20:31

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

struct segtree {
    int n; vector<ll> t;

    segtree(int siz) {
        n = siz;
        t.resize(2 * n);
        for(int i = n-1; i >= 0; i--) {
            t[i] = min(t[i<<1], t[i<<1|1]);
        }
    }

    void update(ll pos, ll x) {
        for(t[pos+=n] = x; pos>1; pos>>=1) t[pos>>1] = min(t[pos], t[pos ^ 1]);
    }

    ll query(ll l, ll r) {
        ll res = 4e18;
        for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if(l&1) ckmin(res, t[l++]);
            if(r&1) ckmin(res, t[--r]);
        }
        return res;
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    segtree seg(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.update(i, x);
    }

    for(;q--;) {
        int type; cin >> type;
        if(type==1) {
            int p, x; cin >> p >> x;
            --p;
            seg.update(p, x);
        } else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << seg.query(l, ++r) << nl;
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

