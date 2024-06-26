#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, k; cin >> n >> k;
    //dp[i] = number of good strings that last min k chars is string i in integer form
    vector<int> good;
    for(int msk = 0; msk < 1 << k; msk++) {
        int ok = 1;
        for(int i = 0, j = k-1; i < j; i++, j--) {
            if((msk >> i & 1) != (msk >> j & 1)) {
                ok = 0;
                break;
            }
        }
        if(!ok) good.emplace_back(msk);
    }
    
    vector<int> dp1(1 << k-1), dp2(1 << k-1);
    string s; cin >> s;
    int a_msk{}, q_msk{};
    for(auto ss : s | views::take(k-1)) {
        (a_msk*=2) += ss == 'A';
        (q_msk*=2) += ss != '?';
        debug(a_msk, q_msk, ss);
    }
    for(int i{q_msk}; i < 1 << k - 1; ++i|=q_msk) {
        dp1[i^a_msk] = 1;
        debug(i, dp1);
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

