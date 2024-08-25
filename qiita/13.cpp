// Problem: E - おせんべい
// Contest: 第７回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e
// Time Limit: 10000
// Start: 2024/08/21 16:17:42

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
    int r, c; cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c, 0));
    vector<int> cols(c, 0);
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) {
        cin >> a[i][j];
        if(a[i][j] == 0) cols[j]++;
    }
    
    int ans = 0;
    auto tempcol = cols;
    for(int i = 0; i < (1 << r); i++) {
        int sum = 0;
        for(int j = 0; j < r; j++) {
            if((i >> j) & 1) for(int k = 0; k < c; k++) {
                cols[k] += (a[j][k] ? 1 : -1);
            }
        }
        for(int k = 0; k < c; k++) {
            if(cols[k] <= r/2) {
                sum += r - cols[k];
            } else {
                sum += cols[k];
            }
        }
        ckmax(ans, sum);
        cols = tempcol;
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

