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

void shiina_mashiro() {
    int n, m, l; cin >> n >> m >> l;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    vector<vector<ar<ll, 2>>> sets(n);
    for(int i = 0; i < l; i++) {
        ll c, d; cin >> c >> d;
        c--;d--;
        sets[c].pb({b[d], d});
    }
    
    debug(a, b, sets);
    set<ar<ll, 2>, greater<ar<ll, 2>>> s;

    for(ll i = 0; i < m; i++) s.insert({b[i], i});
    debug(s);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        vector<ar<ll, 2>> save;
        for(auto &[e1, e2]: sets[i]) {
            s.erase(s.find({e1, e2}));
            save.pb({e1, e2});
        }
        debug(*s.begin());
        ckmax(ans, (ll)(a[i])+(*s.begin())[0]);
        for(auto &pr : save) s.insert(pr);
    }

    cout<<ans<<nl;

}   

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

