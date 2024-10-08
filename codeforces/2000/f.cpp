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
const ll INFLL = 1LL<<60;

ll dp[1005][105];

void shiina_mashiro() {
    ll n, k; cin >> n >> k;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= k; j++) dp[i][j] = INFLL; 
    dp[0][0] = 0;
    for(ll q = 0; q < n; q++) {
        ll a, b; cin >> a >> b;
        vector<ll> ops(a+b+1, INFLL);
        for(ll i = 0; i <= a; i++) for(ll j = 0; j <= b; j++) ckmin(ops[i+j], i*b + j*a - i*j);
        for(ll i = 0; i <= a+b; i++) for(ll j = 0; j <= k; j++) ckmin(dp[q+1][min(i+j, k)], dp[q][j] + ops[i]); //
    }
    cout<<(dp[n][k]==INFLL ? -1 : dp[n][k]) <<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

