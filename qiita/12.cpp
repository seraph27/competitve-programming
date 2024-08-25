// Problem: D - 派閥
// Contest: AtCoder Beginner Contest 002
// URL: https://atcoder.jp/contests/abc002/tasks/abc002_4
// Time Limit: 2000
// Start: 2024/08/21 15:44:26

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
    int n, m; cin >> n >> m;
    int mx = 0;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        edges[a][b] = 1;
        edges[b][a] = 1; 
    }

    for(int i = 0; i < (1 << n); i++) {
        int ok = 1;
        vector<int> vi;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                vi.pb(j);
            }
        }
        for(int j = 0; j < vi.size(); j++) {
            for(int k = j+1; k < vi.size(); k++) {
                if(!edges[vi[j]][vi[k]]) {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) ckmax(mx, (int)vi.size());
    }
    cout << mx << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

