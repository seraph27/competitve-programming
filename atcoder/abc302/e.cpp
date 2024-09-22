// Problem: E - Isolation
// Contest: トヨタ自動車プログラミングコンテスト2023#2(AtCoder Beginner Contest 302)
// URL: https://atcoder.jp/contests/abc302/tasks/abc302_e
// Time Limit: 2000
// Start: 2024/09/06 0:36:25

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
    int n, q; cin >> n >> q;

    int cnt = n;
    vector<int> deg(n+1);
    vector<set<int>> adj(n+1);
    for(;q--;) {
        int type; cin >> type;
        if(type==1) {
            int u, v; cin >> u >> v;
            if(deg[u]==0 && deg[v]==0) {
                cnt-=2;
            } else if(deg[u]==0 || deg[v]==0) {
                cnt-=1;
            }
            deg[u]++, deg[v]++;
            adj[u].insert(v);
            adj[v].insert(u);

        } else {
            int v; cin >> v;
            if(deg[v]!=0) {
                cnt++;
                deg[v] = 0;
            }

            for(auto &e: adj[v]) {
                adj[e].erase(v);
                if(deg[e]==1) cnt++;
                deg[e]--;
            }
            adj[v].clear();
        }
        cout << cnt << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

