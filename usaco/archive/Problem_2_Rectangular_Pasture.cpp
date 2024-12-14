#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 1001001001;

const int NX = 2505;
int grid[NX][NX];
ll prefsum(int x1, int y1, int x2, int y2) {
    return grid[x2][y2] - (y1-1>=0 ? grid[x2][y1-1] : 0) - (x1-1>=0 ? grid[x1-1][y2] : 0) + (x1-1>=0 && y1-1>=0 ? grid[x1-1][y1-1] : 0);
}
void seraph() {
    int n; cin >> n;
    vector<pii> coords(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        coords[i] = {x, y};
    }
    sort(all(coords));
    for(int i = 0; i < n; i++){
        coords[i].first = i+1;
    }
    sort(all(coords), [&](pii a, pii b) {return a.second < b.second;});
    for(int i = 0; i < n; i++){
        coords[i].second = i+1;
    }                                       

    memset(grid, 0, sizeof(grid));
    for(int i = 0; i < coords.size(); i++){
        grid[coords[i].first-1][coords[i].second-1] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] += ((j-1>=0 ? grid[i][j-1] : 0) + (i-1>=0 ? grid[i-1][j] : 0) - ((j-1>=0 && i-1>=0) ? grid[i-1][j-1] : 0));
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int xx1 = min(coords[i].first, coords[j].first) - 1;
            int xx2 = max(coords[i].first, coords[j].first) - 1;
            ans += prefsum(0, i, xx1, j) * prefsum(xx2, i, n-1, j);
        }
    }
    cout << ans + 1 << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("stacking.in","r",stdin); freopen("stacking.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}