// Problem: E - Sightseeing Tour
// Contest: AtCoder Beginner Contest 369
// URL: https://atcoder.jp/contests/abc369/tasks/abc369_e
// Time Limit: 4000
// Start: Mon Oct 21 01:29:45 2024
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    int n, m; cin >> n >> m;
    ll dist[n+5][n+5];
    vector<ll> u(m+1), v(m+1), t(m+1);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        if(i==j) dist[i][j] = 0;
        else dist[i][j] = 5e17;
    }
    for(int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> t[i];
        ckmin(dist[u[i]][v[i]], t[i]);
        ckmin(dist[v[i]][u[i]], t[i]);
    }
    for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
        ckmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
    int q; cin >> q;
    while(q--) {
        int k; cin >> k;
        vector<int> b(k);
        for(auto &x: b) cin >> x;
        vector<int> p(k);
        iota(all(p), 0);
        ll ans = 1e18;
        ll dp[5][2]; //end at u or v
        do {
            dp[0][0] = dist[1][v[b[p[0]]]] + t[b[p[0]]];
            dp[0][1] = dist[1][u[b[p[0]]]] + t[b[p[0]]];
            for(int i = 0; i < k-1; i++) {
                dp[i+1][0] = min(dp[i][0] + dist[u[b[p[i]]]][v[b[p[i+1]]]], dp[i][1] + dist[v[b[p[i]]]][v[b[p[i+1]]]]) + t[b[p[i+1]]];
                dp[i+1][1] = min(dp[i][0] + dist[u[b[p[i]]]][u[b[p[i+1]]]], dp[i][1] + dist[v[b[p[i]]]][u[b[p[i+1]]]]) + t[b[p[i+1]]];
                debug(i, dp[i+1][0], dp[i+1][1]);
            }
            assert(dp[k-1][0]>=0 && dp[k-1][1]>=0);
            ckmin(ans, dp[k-1][0] + dist[u[b[p[k-1]]]][n]);
            ckmin(ans, dp[k-1][1] + dist[v[b[p[k-1]]]][n]);
        } while(next_permutation(all(p)));

        cout << ans << nl;
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

