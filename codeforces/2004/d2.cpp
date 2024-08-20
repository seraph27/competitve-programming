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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    map<string, vector<int>> mp;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        mp[s].pb(i);
        vi[i] = s;
    }
    debug(mp);

    for(;q--;) {
        int x, y; cin >> x >> y;
        --x; --y;
        if(x>y) swap(x, y);
        string sx = vi[x], sy = vi[y];
        if(!(sx[0] != sy[0] && sx[0] != sy[1] && sx[1] != sy[0] && sx[1] != sy[1])) {
            cout << y - x << nl;
            continue;
        }
        
        int ans = INF;
        for(auto it = mp.begin(); it != mp.end(); ++it) if(it->first != vi[x] && it->first != vi[y]) {
            auto dist = lower_bound(all(it->second), x) - it->second.begin();
            for(auto j : {dist-1, dist}) if(j>=0 && j < it->second.size()) {
                auto v = it->second[j];
                debug(v);
                ckmin(ans, abs(x - v) + abs(v - y));
            }
        }
        cout << (ans == INF ? -1 : ans) << nl;
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

