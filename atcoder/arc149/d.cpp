// Problem: D - mod M Game
// Contest: AtCoder Regular Contest 148
// URL: https://atcoder.jp/contests/arc148/tasks/arc148_d
// Time Limit: 2000
// Start: 2024/09/17 21:54:37

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
    map<int, int> mp;
    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int ok = 1;
    for(auto&[k, v] : mp) {
        if(v%=2) {
            ok = 0;
        }
    }

    if(ok) {
        cout << "Bob" << nl;
        return;
    }
    if(m%2) {
        cout << "Alice" << nl;
        return;
    }

    for(auto &[k, v] : mp) {
        if(v) {
            debug(mp);
            int match = (k+m/2) % m;
            debug(match);
            if(!mp[match]) {
                cout << "Alice" << nl;
                return;
            }
            mp[k]--;
            mp[match]--;
        }
    }
    cout << "Bob" << nl;
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

