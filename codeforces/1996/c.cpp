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
    int n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    vector<ar<int, 26>> pref_a(n+1);
    vector<ar<int, 26>> pref_b(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            pref_a[i][j] = pref_a[i-1][j] + (bool)(a[i-1]-'a' == j);
            pref_b[i][j] = pref_b[i-1][j] + (bool)(b[i-1]-'a' == j);
        }
    }
    for(;q--;) {
        ll ans = 0;
        int l, r; cin >> l >> r;
        for(int j = 0; j < 26; j++) {
            auto a_cnt = pref_a[r][j]-pref_a[l-1][j];
            auto b_cnt = pref_b[r][j]-pref_b[l-1][j];
            ans+=abs(a_cnt - b_cnt);
        }
        cout<<ans/2<<nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

