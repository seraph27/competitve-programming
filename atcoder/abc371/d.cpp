#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    vector<int> mp;
    vector<int> x(n+1), p(n+1);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> p[i];

    for(int i = 0; i < n; i++) {
        mp.pb(x[i]);
    }

    int q; cin >> q;
    vector<ar<int, 2>> que(q+1);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        que[i] = {l, r};
    }
    sort(all(mp));
    int sz = mp.size()+5;
    vector<ll> pref(sz, 0);
    for(int i = 0; i < mp.size(); i++) {
        pref[i+1] += pref[i] + p[i];
    }
    for(int i = 0; i < q; i++) {
        auto &[l, r] = que[i];
        int L = lower_bound(all(mp), l) - mp.begin();
        int R = upper_bound(all(mp), r) - mp.begin();
        cout<<pref[R] - pref[L]<<nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}
