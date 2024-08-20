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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> vii(n);
    for(int i = 0; i < n; i++) cin >>vii[i].first;
    for(int i = 0; i < n; i++) cin >>vii[i].second;
    sort(all(vii));
    vii.pb({4e18, 0LL});
    vector<ll> vi(n+1), cnt(n+1);
    for(int i = 0; i < n+1; i++) vi[i]=vii[i].first, cnt[i]=vii[i].second;
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll x = min(m/vi[i], cnt[i]);
        auto cntnxt = vi[i+1]-vi[i]<=1 ? cnt[i+1] : 0; 
        ll y = min((m-(x*vi[i])) / (vi[i+1]), cntnxt);  //after buying as many x, how many more can you buy from k+1? 
        ll buf = min(x, cntnxt-y); //the amount you can shift is bounded by (x and how many y you can shift over to gain +1)
        ckmax(ans, min(vi[i]*x+vi[i+1]*y+buf, m));
    }
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}
