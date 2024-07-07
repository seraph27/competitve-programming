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

void seraph() {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    int mn = abs(a-b), mx = a+b <=60 ? a+b : 120-a-b;
    debug(mn, mx);
    auto cpop = __builtin_popcountll(c);
    if(cpop < mn || cpop > mx || (cpop&1) != (mn&1)) {
        cout << -1 << nl;
        return;
    }

    ll x = 0, y = 0;
    auto set = [&](int i) -> bool {
        return (x & (1LL << i)) || (y & (1LL << i));
    };
    int mnn = min(cpop, a+b);
    while(mnn--) {
        for(int i = 0; i < 60; i++) {
            if(c & (1LL << i) && !set(i)) {
                if(a >= b) {
                    x |= (1LL << i);
                    a--;
                } else {y|= (1LL << i); b--;}
                break;
            }
        }
    }
    while(a > 0 || b > 0) {
        for(int i = 0; i < 60; i++) {
            if((((c & (1LL << i)) == 0) && !set(i))) {
                x |= (1LL << i);
                y |= (1LL << i);
                a--; b--;
                break;
            }
        }
    }
    cout << x << " " << y << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

