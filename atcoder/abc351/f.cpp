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

struct fenwick {
    vector<ll> ar;
    int sz;

    fenwick(int n) {
        sz = n+1;
        ar.assign(n+1, 0);
    }

    void add(int idx, int x) {
        for(++idx; idx < sz; idx += idx & -idx) ar[idx]+=x;
    }

    ll query(int idx) {
        ll res = 0;
        for(++idx; idx > 0; idx -= idx & -idx) res += ar[idx];
        return res;
    }
    ll query(int l, int r) {
        return query(r)-query(l-1);
    }
};

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    vector<int> temp = vi;
    sort(all(temp));
    temp.erase(unique(all(temp)), temp.end());
    vector<int> idx(n);
    for(int i = 0; i < n; i++) {
        idx[i] = lower_bound(all(temp), vi[i]) - temp.begin();
    }
    fenwick f1(n);
    fenwick f2(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (ll)f1.query(idx[i]) * temp[idx[i]] - f2.query(idx[i]);
        f1.add(idx[i], 1);
        f2.add(idx[i], temp[idx[i]]);
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

