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
    int n; cin >> n;
    string s; cin >> s;
    int SZ = s.size();
    ll ans = 1e18;
    for(int sp = 0; sp < SZ-1; sp++){
        vector<ll> each;
        for(int i = 0; i < SZ; i++){
            if(sp==i) each.emplace_back(((s[i]-'0')*10) + s[i+1]-'0'), i++;
            else each.emplace_back(s[i]-'0');
        }
        vector<ll> dp(SZ-1, 1e18);
        for(int i = 0; i < SZ-1; i++) {
            ll mul = 1;
            for(int j = i; j < SZ-1; j++) {
                mul*=each[j];
                ckmin(mul, (ll)1e15);
                ckmin(dp[j], (i ? dp[i-1] : 0) + mul); //the reason this works, is because u try to improve the score, so in each iteration of i, you can decide to add
                debug(dp, i, j, sp);
            }
        }
        ckmin(ans, dp.back());
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

