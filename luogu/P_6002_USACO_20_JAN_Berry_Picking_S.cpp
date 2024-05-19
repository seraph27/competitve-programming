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
    int n, k; cin >> n >> k;
    vector<int> s(n);
    int big = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        s[i] = a;
        ckmax(big, a);
    }
    int ans = 0;
    for(int cnt = 1; cnt <= big; cnt++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (s[i] / cnt);
        }
        if(sum < k/2) break;
        if(sum >= k) {
            ckmax(ans, k * cnt / 2);
            continue;
        }
        sort(all(s), [&](int a, int b){return a % cnt > b % cnt;});
        debug(s, cnt);
        int tot = cnt * (sum - k / 2);
        debug(tot);
        for(int i = 0; i < n && i + sum < k; i++){
            debug(i);
            tot += s[i] % cnt;
        }
        ckmax(ans, tot);
    }
    cout << ans << nl;
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}