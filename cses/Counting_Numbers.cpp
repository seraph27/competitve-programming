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
    ll a, b; cin >> a >> b;
    vector<int> digits;
    int sz;
    auto solve = [&]() -> ll {
        vector<vector<vector<vector<ll>>>> dp(sz+1, vector<vector<vector<ll>>>(2, vector<vector<ll>>(11, vector<ll>(2, 0))));
        dp[sz][0][10][1] = 1;
        for(int i = sz; i > 0; i--) {
            for(int ls = 0; ls < 2; ls++) {
                for(int num = 0; num <= 10; num++) {
                    for(int lz = 0; lz < 2; lz++) {
                        auto now = dp[i][ls][num][lz];
                        if(now == 0) continue;
                        int lim = (ls ? 9 : digits[i-1]);
                        for(int d = 0; d <= lim; d++) {
                            ll has_lz = (lz && d == 0);
                            if(d == num && d != 0) continue;
                            if(d == num && d == 0 && lz == 0) continue;
                            dp[i-1][ls | (d < lim)][d][has_lz] += now;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < 10; i++) ans+=dp[0][1][i][0];
        return ans;
    };

    auto cnt = [&](ll lim) -> ll {
        lim++;
        digits.clear();
        while(lim > 0) {
            digits.pb(lim%10);
            lim/=10;
        }
        sz = (int)digits.size();

        debug(digits, sz);
        auto res = solve();
        debug(res);
        return res;
    };

    cout<<cnt(b) - cnt(a-1) + (a==0)<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

