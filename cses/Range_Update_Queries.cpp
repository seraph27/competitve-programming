// Problem: Range Update Queries
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1651
// Time Limit: 1000
// Start: 2024/09/09 23:37:55

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
    int n;

    segtree(int siz) {
        n = siz;
        t.resize(siz * 2);
        for(int i = n-1; i >= 0; i--) t[i] = t[i<<1] + t[i<<1|1];
    } 

    void update(int l, int r, int x) {
        for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
            if(l&1) t[l++]+=x;
            if(r&1) t[--r]+=x; 
        }
    }

    ll query(int p) {
        ll res = 0;
        for(p+=n;p>0;p>>=1) res+=t[p];
        return res;
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    segtree seg(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.update(i, i+1, x);
    }
    for(;q--;) {
        int type; cin >> type;
        if(type==1) {
            ll l, r, x; cin >> l >> r >> x;
            --l;--r;
            seg.update(l, r+1, x);
        } else {
            int x; cin >> x;
            --x;
            cout << seg.query(x) << nl;
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

