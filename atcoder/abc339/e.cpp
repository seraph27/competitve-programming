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
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

const int SZ = 1<<19;
ll n, a[SZ], t[SZ<<1];

void build(ll l, ll r, ll p) {
    if(l == r) {t[p] = a[l]; return;}
    ll m = (l+r)>>1;
    build(l, m, p<<1), build(m+1, r, (p<<1)|1);
    t[p] = max(t[p<<1], t[(p<<1)|1]);
}

void update(ll tl, ll tr, ll p, ll pos, ll val) {
    if(tl == tr) {t[p] = val; return;}
    ll m = (tl+tr)>>1;
    if(pos<=m) update(tl, m, p<<1, pos, val);
    else update(m+1, tr, (p<<1)|1, pos, val);
    t[p] = max(t[p<<1], t[(p<<1)|1]);
}

ll getmx(ll l, ll r, ll tl, ll tr, ll p) {
    if(l<=tl && tr<=r) return t[p];
    ll m = (tl+tr)>>1;
    ll mx = 0;
    if(l<=m) ckmax(mx, getmx(l, r, tl, m, p<<1));
    if(r>m) ckmax(mx, getmx(l, r, m+1, tr, (p<<1)|1));
    return mx;
}
void seraph() {
    //dp[i] = largest subseq such that the last val is i;
    int d; cin >> n >> d;
    vector<int> vi(n);
    for(auto&b: vi) cin >> b;
    const int SZZ = 5e5+5;
    for(int i = 0; i < n; i++) {
        auto currmx = getmx(max(0, vi[i]-d), min(SZZ, vi[i]+d), 1, SZZ, 1);
        debug(currmx);
        update(1, SZZ, 1, vi[i], currmx+1);
    }
    cout << getmx(1, SZZ, 1, SZZ, 1) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int o = 1;
    //cin >> t;
    while (o--) seraph();
}

