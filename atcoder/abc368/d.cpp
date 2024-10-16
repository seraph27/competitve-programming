// Problem: D - Minimum Steiner Tree
// Contest: 日立ヴァンタラプログラミングコンテスト2024（AtCoder Beginner Contest 368）
// URL: https://atcoder.jp/contests/abc368/tasks/abc368_d
// Time Limit: 2000
// Start: 2024/09/11 11:28:13

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
    int n, k; cin >> n >> k;
    vector<set<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<int> vi;
    for(int i = 0; i < k; i++) {
        int a; cin >> a;
        vi.insert(--a);
    }
    
    int ans = n;
    vector<int> bad;
    for(int i = 0; i < n; i++) if(adj[i].size()==1) bad.emplace_back(i);

    debug(bad);
    for(int i = 0; i < sz(bad); i++) {
        if(!vi.count(bad[i])) {
            int temp = *adj[bad[i]].begin();
            adj[bad[i]].clear();
            adj[temp].erase(bad[i]);
            ans--;
            if(adj[temp].size()==1) bad.emplace_back(temp);
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

