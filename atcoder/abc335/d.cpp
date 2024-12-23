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
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    a[n/2][n/2] = -1;
    int dirsX[5] = {1, 0, -1, 0, 1};
    int dirsY[5] = {0, 1, 0, -1, 0};

    int place = 1, mod = 0, i = 0, j = 0;
    while(place<n*n) {
        a[i][j] = place;
        place++;
        auto ny = i+dirsY[mod], nx = j+dirsX[mod];
        debug(ny, nx);
        if(ny<0 || ny>=n || nx<0 || nx>=n || a[ny][nx]!=0) mod++;
        mod%=4;
        i+=dirsY[mod], j+=dirsX[mod];
        debug(i, j);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] == -1) cout<<'T'<<" ";
            else cout<<a[i][j]<<(j==n-1?"":" ");
        }
        cout<<nl;
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

