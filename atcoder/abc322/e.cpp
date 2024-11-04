// Problem: E - Product Development
// Contest: AtCoder Beginner Contest 322
// URL: https://atcoder.jp/contests/abc322/tasks/abc322_e
// Time Limit: 4000
// Start: Fri Nov  1 18:25:04 2024
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
    int n, k, p; cin >> n >> k >> p;
    vector<int> cost(n);
    vector<vector<int>> add(n, vector<int>(k));
    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        cost[i] = c;
        for(int j = 0; j < k; j++) {
            int a; cin >> a;
            add[i][j] = a;
        }
    }
    map<ar<int, 5>, ll> dp;
    dp[{0, 0, 0, 0, 0}] = 0;
    for(int i = 0; i < n; i++) {
        auto dp2 = dp;
        for(auto &[val, c] : dp) {
            auto new_val = val;
            for(int j = 0; j < k; j++) {
                new_val[j] += add[i][j];
                if(new_val[j] > p) {
                    new_val[j] = p;
                }
            }
            if(!dp2.count(new_val)) {
                dp2[new_val] = 4e18;
            }
            ckmin(dp2[new_val], c + cost[i]);
        }
        dp = dp2;
    }
    debug(dp);
    ll ans = 4e18;
    for(auto [val, c] : dp) {
        int ok = 1;
        for(int i = 0; i < k; i++) {
            if(val[i] < p) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            ckmin(ans, (ll)c);
        }
    }
    if(ans == 4e18) {
        cout << -1 << nl;
        return;
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

