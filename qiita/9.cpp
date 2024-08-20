// Problem: D - 星座探し
// Contest: 第７回日本情報オリンピック 予選（過去問）
// URL: https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
// Time Limit: 10000
// Start: 2024/08/20 21:33:59

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
    int m; cin >> m;
    vector<ar<int, 2>> match;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        match.pb({a, b});
    }

    int n; cin >> n;
    vector<ar<int, 2>> star;
    map<ar<int, 2>, int> mp;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        star.pb({a, b});
        mp[{a, b}] = 1;
    }

    for(int i = 0; i < star.size(); i++) {
        auto &[x, y] = star[i];
        int dx = x - match[0][0], dy = y - match[0][1];
        if(dx == 0 && dy == 0) continue;
        int ok = 1;
        for(int j = 0; j < match.size(); j++) {
            if(!mp.count({match[j][0] + dx, match[j][1] + dy})) {
                ok = 0;
                break;
            }
        } 
        if(ok) {
            cout << dx << " " << dy << nl;
            return;
        }
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

