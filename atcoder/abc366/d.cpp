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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n, 0)));
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            for(int z = 0; z < n; z++) {
                int val; cin >> val;
                a[x][y][z] = val;
            }
        }
    }

    vector<vector<vector<int>>> S(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                S[i][j][k] = S[i - 1][j][k] + S[i][j - 1][k] + S[i][j][k - 1] 
                           - S[i - 1][j - 1][k] - S[i][j - 1][k - 1] - S[i - 1][j][k - 1] 
                           + S[i - 1][j - 1][k - 1] + a[i - 1][j - 1][k - 1];
            }
        }
    }
    
    auto solve = [&](int lx, int rx, int ly, int ry, int lz, int rz) -> ll {
        ll ans = S[rx][ry][rz] - S[lx-1][ry][rz] - S[rx][ly-1][rz] - S[rx][ry][lz-1]
               + S[lx-1][ly-1][rz] + S[lx-1][ry][lz-1] + S[rx][ly-1][lz-1] - S[lx-1][ly-1][lz-1];
        debug(S[rx][ry][rz], S[lx-1][ry][rz], S[rx][ly-1][rz],S[rx][ry][lz-1], S[lx-1][ly-1][rz], S[lx-1][ry][lz-1], S[rx][ly-1][lz-1], S[lx-1][ly-1][lz-1]);
        return ans;
    };
    int q; cin >> q;
    for(;q--;) {
        int lx, rx, ly, ry, lz, rz; cin >> lx >> rx >> ly >> ry >> lz >> rz;
        cout << solve(lx, rx, ly, ry, lz, rz) << nl;
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
