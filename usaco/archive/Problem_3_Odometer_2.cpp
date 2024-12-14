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
    ll l, r; cin >> l >> r;
    vector<int> digits;
    int sz;
    ll dp[20][42][2][2];

    auto solve = [&](int tar1, int tar2) -> ll { //op = 1 (<) else =
        memset(dp, 0, sizeof(dp));
        ll ans = 0;
        dp[sz][20][0][0] = 1;
        for(int i = sz; i > 0; i--) {
            for(int k = 0; k < 40; k++) {
                for(int ls = 0; ls < 2; ls++) {
                    for(int st = 0; st < 2; st++) {
                        auto now = dp[i][k][ls][st];
                        if(now==0) continue;
                        int lim = (ls ? 9 : digits[i-1]);
                        for(int d = 0; d <= lim; d++) {
                            bool is_st = st || d != 0;
                            if(is_st && ~tar2 && tar1 != d && tar2 != d) continue;
                            int newk = k;
                            if(is_st) newk += (tar1==d ? 1 : -1);
                            dp[i-1][newk][ls | (d < lim)][is_st] += now;
                        }
                    }
                }
            }
        }
        if(~tar2) {
            ans += dp[0][20][1][1];
        } else{
            for(int k = 20; k < 40; k++) {
                ans+= dp[0][k][1][1];
            }
        }
        return ans;
    };

    auto cnt = [&](ll lim) -> ll {
        lim++;
        digits.clear();
        while(lim>0) {
            digits.pb(lim%10);
            lim/=10;
        }
        sz = (int)digits.size();
        ll ans1 = 0, ans2 = 0;
        for(int i = 0; i <= 9; i++) {
            ans1+=solve(i, -1);
        }
        debug(ans1);
        for(int i = 0; i <= 9; i++) for(int j = 0; j <= 9; j++) {
            ans2+=solve(i, j);
        }
        debug(ans2);
        return ans1 - ans2/2;
    };

    cout<<cnt(r) - cnt(l-1)<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("odometer.in","r",stdin); freopen("odometer.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
