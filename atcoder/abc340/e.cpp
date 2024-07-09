#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

using mint = modint998244353;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

struct fuck {
    vector<ll> ar;
    ll sz;

    fuck(int n) {
        sz = n+1;
        ar.assign(n+1, 0);
    }

    void add(ll idx, ll x) {
        for(++idx; idx < sz; idx += idx & -idx) ar[idx]+=x;
    }
    
    ll query(ll idx) {
        ll sum = 0;
        for(++idx; idx > 0; idx -= idx & -idx) sum+=ar[idx];
        return sum;
    }

    void range_add(ll l, ll r, ll x) {
        add(l, x);
        add(r+1, -x);
    }
};

void seraph() {
    ll n, m; cin >> n >> m;
    vector<ll> box(n);
    for(auto&a: box) cin >> a;
    
    fuck fw(n+1);
    for(int i = 0; i < n; i++) {
        fw.range_add(i+1, i+1, box[i]);
    }

    for(;m--;) {
        ll q; cin >> q;
        q++;
        ll rn = fw.query(q);
        fw.range_add(q ,q, -rn);
        ll cnt = rn/n, mod = rn%n;
        if(cnt>0) fw.range_add(1, n, cnt);
        ll les = 0;
        if(q < n) {
            fw.range_add(q+1, min(q+mod, n), 1);
            les = min(mod, n-q); 
        }
        if(q+mod>=n) fw.range_add(1, mod-les, 1);
    }

    for(int i = 1; i <= n; i++) {
        cout << fw.query(i) << " ";
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

