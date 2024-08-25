// Problem: B - ピザ
// Contest: 第８回日本情報オリンピック 本選（過去問）
// URL: https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
// Time Limit: 2000
// Start: 2024/08/22 15:05:37

//minimal template
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
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

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int d; cin >> d;
    int n, m; cin >> n >> m;
    vector<int> vi(n);
    for(int i = 1; i < n; i++) {
        cin >> vi[i];
    }
    vi.pb(-1);
    sort(all(vi));
    vi[0] = vi[sz(vi)-1] - d;
    vi.pb(vi[1] + d);
    debug(vi);
    
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        int q; cin >> q;
        auto it = lower_bound(all(vi), q) - vi.begin();
        ll mindist = 4e18;
        for(auto j : {it-1, it}) if(j >= 0 && j < sz(vi)) {
            ckmin(mindist, (ll)abs(vi[j]-q));
        }
        ans += mindist;
    }
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

