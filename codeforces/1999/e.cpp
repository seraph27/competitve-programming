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
    vector<pii> pow;
    int need = 1;
    for(int i = 1, base = 1; i < 14; i++, base*=3) {
        pow.pb({base, need});
        need++;
    }
    ll l, r; cin >> l >> r;
    ll last = l;
    ll ans = 0;
    int flag = 0;
    int firstflag = 1;
    ll las = 0;
    for(int i = 0; i < pow.size(); i++) {

        if(flag) break;
        ll now = min(r+1, pow[i].first);
 
        if(now == r+1) {
            flag = 1;
        }
        ll minus = max(0LL, now - last);
        if(minus-las != 0 && firstflag) {
            ans+=pow[i].second-1;
            firstflag = 0;
        }
        ans += (minus - las)* (pow[i].second-1);
        debug(minus - las, pow[i].second-1);
        las = minus;
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

