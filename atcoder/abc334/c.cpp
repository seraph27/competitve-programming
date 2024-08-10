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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<ll> socks(k);
    for(auto&a: socks) cin >> a;
    if(k%2 == 0) {
        ll ans = 0;
        for(int i = 0; i < k-1; i+=2) {
            ans += socks[i+1] - socks[i];
        }
        cout << ans << nl;
        return;
    }
    vector<ll> prefF(1, 0), prefB(1, 0);
    for(int i = 0; i < k-1; i+=2) {
        prefF.pb(socks[i+1] - socks[i]);
        prefF[prefF.size()-1] += prefF[prefF.size()-2];
    }
    for(int i = k-1; i > 0; i-=2) {
        prefB.pb(socks[i] - socks[i-1]);
        prefB[prefB.size()-1] += prefB[prefB.size()-2];
    }
    debug(prefF, prefB);

    ll ans = 4e18;
    debug(prefF, prefB);
    for(int i = 0; i < k; i+=2) {
        auto F = prefF[i/2];
        auto B = prefB[(k-i-1)/2];
        ckmin(ans, F + B);
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

