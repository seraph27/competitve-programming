// Problem: Static Range Sum Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1646
// Time Limit: 1000
// Start: 2024/09/09 16:50:07

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
    vector<ll> t;
    ll n;
    segtree(int siz, vector<int> &vi) {
        n = siz;
        t.resize(2*n);
        for(int i = 0; i < n; i++) t[i+n] = vi[i];
        for(int i = n-1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
    }

    void update(int p, ll x) {
        for(t[p+n] = x; p > 1; p>>=1) t[p>>1] = t[p] + t[p^1];
    }

    ll query(int l, int r) {
        ll res = 0;
        for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if(l&1) res+=t[l++];
            if(r&1) res+=t[--r];
        }
        return res;
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    segtree seg(n, vi);

    for(;q--;) {
        int l, r; cin >> l >> r;
        cout << seg.query(--l, r) << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

