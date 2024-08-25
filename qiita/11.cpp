// Problem: C - Switches
// Contest: AtCoder Beginner Contest 128
// URL: https://atcoder.jp/contests/abc128/tasks/abc128_c
// Time Limit: 2000
// Start: 2024/08/21 15:13:00

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
    int n, m; cin >> n >> m;
    vector<vector<int>> light(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            --x;
            light[i][x] = 1;
        }
    }

    vector<int> mod(m);
    for(int i = 0; i < m; i++) cin >> mod[i];
    
    int sum = 0;
    for(int i = 0; i < (1 << n); i++) {
        int ok = 1;
        for(int k = 0; k < m; k++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(((i >> j) & 1) && light[k][j]) {
                   cnt++;
                }
            }
            if((cnt-mod[k]+2) % 2) {
                ok = 0;
                break;
            }
        }
        if(ok) sum++;
    }

    cout << sum << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

