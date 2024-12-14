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
    ll dp[19][42][2][2];

    auto solve = [&](auto&&s, int pos, int k, int op, int started, int tar1, int tar2) -> ll { //op = 1 (<) else =
        if(pos == sz) {
            if(!started) return 0;
            if(tar2 != -1) {
                if(k==20) return 1;
                else return 0;
            }
            if(k>=20) return 1;
            else return 0;
        }

        if(dp[pos][k][op][started]!=-1) return dp[pos][k][op][started];
        ll ans = 0;

        int lim = (op ? 9 : digits[pos]);
        for(int d = 0; d <= lim; d++) {
            bool is_start = started || d != 0;
            if(is_start && tar2 != -1 && d != tar1 && d != tar2) continue;
            int newk = k;
            if(is_start){
                newk += (tar1==d ? 1 : -1);
            }
            ans+=s(s, pos+1, newk, op | (d < lim), is_start, tar1, tar2);
        }
        return dp[pos][k][op][started] = ans;
    };

    auto cnt = [&](ll lim) -> ll {
        digits.clear();
        while(lim>0) {
            digits.pb(lim%10);
            lim/=10;
        }
        reverse(all(digits));
        sz = (int)digits.size();
        debug(digits);

        ll ans = 0;
        for(int i = 0; i <= 9; i++) {
            memset(dp, -1, sizeof(dp));
            ans+=solve(solve, 0, 20, 0, 0, i, -1);
        }
        debug(ans);
        ll ans2 = 0;
        for(int i = 0; i <= 9; i++) for(int j = 0; j <= 9; j++) {
            memset(dp, -1, sizeof(dp));
            ans2+=solve(solve, 0, 20, 0, 0, i, j);
        }
        debug(ans2);
        return ans - ans2/2;
    };

    cout<<cnt(r) - cnt(l-1)<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("odometer.in","r",stdin); freopen("odometer.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

