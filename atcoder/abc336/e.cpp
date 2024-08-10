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
    ll n; cin >> n;
    n++;
    vector<int> digits;
    while(n>0) {
        digits.pb(n%10);
        n/=10;
    }
    int sz = (int)digits.size();
    ll ans = 0;
    for(int sum = 1; sum <= sz*9; sum++) {
        ll dp[sz+1][2][sum+1][sum+1];
        memset(dp, 0, sizeof(dp));
        dp[sz][0][0][0] = 1;
        for(int i = sz; i > 0; i--) {
            for(int ls = 0; ls < 2; ls++) {
                for(int s = 0; s <= sum; s++) {
                    for(int r = 0; r < sum; r++) {
                        ll now = dp[i][ls][s][r];
                        if(now==0) continue;
                        int lim = (ls ? 9 : digits[i-1]);
                        for(int d = 0; d <= lim && s + d <= sum; d++) {
                            dp[i - 1][ls | (d < lim)][s + d][(r*10+d)%sum] += now;
                        }
                    }
                }
            }
        }
        ans += dp[0][1][sum][0];
    }
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

