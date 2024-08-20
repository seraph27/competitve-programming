// Problem: C - 最古の遺跡
// Contest: 第６回日本情報オリンピック 本選（過去問）
// URL: https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
// Time Limit: 3000
// Start: 2024/08/19 21:42:21

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
    int n; cin >> n;
    vector<ar<int, 2>> pts(n);
    set<ar<int, 2>> mp;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pts[i] = {a, b};
        mp.insert({a, b}); 
    }

    auto area = [&](int dx, int dy) -> int {
        return dx*dx + dy*dy;
    };
    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = i; j < n; j++) {
        auto &[x1, y1] = pts[i]; 
        auto &[x2, y2] = pts[j];
        int dy = abs(y2 - y1), dx = abs(x2 - x1);
        swap(dy, dx);
        if((y2-y1 > 0 && x2-x1 > 0) || (y2-y1 < 0 && y2-y1 < 0)) {
            if(mp.count({x1 + dx, y1 - dy}) && mp.count({x2 + dx, y2 - dy})) ckmax(ans, area(dx, dy)); 
            if(mp.count({x1 - dx, y1 + dy}) && mp.count({x2 - dx, y2 + dy})) ckmax(ans, area(dx, dy)); 
        } else {
            if(mp.count({x1 + dx, y1 + dy}) && mp.count({x2 + dx, y2 + dy})) ckmax(ans, area(dx, dy)); 
            if(mp.count({x1 - dx, y1 - dy}) && mp.count({x2 - dx, y2 - dy})) ckmax(ans, area(dx, dy)); 
        }
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

