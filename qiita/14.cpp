// Problem: B - Buildings are Colorful!
// Contest: square869120Contest #4
// URL: https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b
// Time Limit: 1000
// Start: 2024/08/21 17:09:06

//minimal template
#include <bits/stdc++.h>
#define sz(x) x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
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

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];

    ll ans = 4e18;
    auto temp = vi;
    for(int i = 0; i < (1 << n); i++) {
        vector<int> mark(n, 0);
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                cnt++;
                mark[j] = 1;
            }
        }
        if(cnt < k) continue;
        ll sum = 0;
        for(int j = 1; j < vi.size(); j++) {
            if(!mark[j]) {
                vi[j] = max(vi[j], vi[j-1]);
                continue;
            }
            if(vi[j] <= vi[j-1]) {
                sum += vi[j-1] - vi[j] + 1;
                vi[j] = vi[j-1]+1;
            }
        }
        ckmin(ans, sum);
        vi = temp;
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

