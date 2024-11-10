#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define fi first 
#define se second
using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for(auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ')';}
template<typename T, typename... V> 
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ",", _print(v...); else cerr << "]\n"; }}; 
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else 
#define debug(x...)
#endif

struct DSU {
    vector<int> f, siz;
    
}

const char nl = '\n';

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> coords(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        coords[i].first = a;
        coords[i].second = b;
    }

    double ans = 1e9;
    auto dist = [&](int x1, int y1, int x2, int y2) -> double {
        int one = y1-y2, two = x1-x2;
        return sqrt(one*one + two*two);
    };
    if(n==2) {
        cout << dist(coords[0].fi, coords[0].se, coords[1].fi, coords[1].se) << nl;
        return;
    }

    for(int i = 0; i < n; i++) {
        vector<double> vi;
        for(int j = 0; j < n; j++) {
            if(i==j) continue;
            auto dis = dist(coords[j].fi, coords[j].se, coords[i].fi, coords[i].se);
            vi.pb(dis);
        }
        sort(all(vi));
        auto sum = vi[sz(vi)-1] + vi[sz(vi)-2];
        ckmin(ans, sum);
    }

    cout << fixed << setprecision(10) << ans << nl;
}

signed main() {
    int t = 1;
    while(t--) {
        solve();
    }
}