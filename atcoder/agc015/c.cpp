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

string a[2005];
int pref[2005][2005], x[2005][2005], y[2005][2005];
void seraph() {
    int n, m; cin >> n >> m;
    int q; cin >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(a[i-1][j-1]=='1') pref[i][j] = 1;
        pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(a[i-1][j-1]=='1' && a[i-1][j] == '1') x[i][j] = 1;
        x[i][j] += x[i-1][j] + x[i][j-1] - x[i-1][j-1];
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        if(a[i-1][j-1]=='1' && a[i][j-1] == '1') y[i][j] = 1;
        y[i][j] += y[i-1][j] + y[i][j-1] - y[i-1][j-1];
    }

    auto query = [&](auto &mat, auto x1, auto y1, auto x2, auto y2) -> int {
        return mat[x2][y2] - mat[x2][y1-1] - mat[x1-1][y2] + mat[x1-1][y1-1];
    };
    for(;q--;) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        auto vtx = query(pref, x1, y1, x2, y2); 
        auto edge = query(x, x1, y1, x2, y2) - query(x, x1, y2, x2, y2);
        auto edge2 = query(y, x1, y1, x2, y2) - query(y, x2, y1, x2, y2);
        debug(vtx, edge, edge2);
        cout<<vtx-edge-edge2<<nl;
    }
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

