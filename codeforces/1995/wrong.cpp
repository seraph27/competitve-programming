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
    vector<ll> vi(n), cnt(n);
    for(auto&a: vi) cin >> a;
    for(auto&a: cnt) cin >> a;
    vi.pb(4e18);
    vector<pair<ll, ll>> paired(n);
    for (int i = 0; i < n; ++i) {
        paired[i] = {vi[i], cnt[i]};
    }
    sort(all(paired));
    for (int i = 0; i < n; ++i) {
        vi[i] = paired[i].first;
        cnt[i] = paired[i].second;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll tot = vi[i]*min((m/vi[i]), cnt[i]);
        if(vi[i+1]-vi[i]>1) {
            ckmax(ans, tot);
            continue;
        }
        ll buffer = min(cnt[i], cnt[i+1]);
        auto left = (m-tot)/vi[i+1];
        buffer=min({buffer, cnt[i+1]-left, m/vi[i]});
        tot+=vi[i+1]*min(cnt[i+1], left);
        debug(buffer);
        
        if(buffer<0) buffer = 0;
        ckmax(ans, min(tot+buffer, m));
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
