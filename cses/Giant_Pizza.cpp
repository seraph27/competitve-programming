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
const int INF = 0x3f3f3f3f;

void seraph() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(2*m+2);
    vector<vector<int>> radj(2*m+2);
    vector<int> vis(2*m+2, 0), rep(2*m+2, 0), stk;
    for(int i = 0; i < n; i++){
        char c1, c2; int x1, x2;
        cin >> c1 >> x1 >> c2 >> x2; 
        --x1; --x2;
        x1 = 2*x1 ^ (c1 == '+');
        x2 = 2*x2 ^ (c2 == '+');
        int negx1 = x1 ^ 1;
        int negx2 = x2 ^ 1;
        debug(x1, x2, negx1, negx2);
        adj[negx1].push_back(x2);
        adj[negx2].push_back(x1);
        radj[x1].push_back(negx2);
        radj[x2].push_back(negx1);
    }

    auto dfs1 = [&](auto&&dfs1, int v) -> void {
        vis[v] = 1;
        for(auto &e: adj[v]){
            if(!vis[e]){
                dfs1(dfs1, e);
            }
        }
        stk.push_back(v);
    };

    auto dfs2 = [&](auto&&dfs2, int v, int i) -> void {
        vis[v] = 1;
        rep[v] = i;
        for(auto &e: radj[v]){
            if(rep[e] == -1){
                dfs2(dfs2, e, i);
            }
        }
    };

    for(int i = 0; i <= 2*m+2; i++){
        if(!vis[i]) dfs1(dfs1, i);
    }
    vis.assign(2*m+2, 0);
    rep.assign(2*m+2, -1);
    while(!stk.empty()) {
        int top = stk.back(); stk.pop_back();
        debug(top);
        if(rep[top] == -1) dfs2(dfs2, top, top);
    }

    debug(rep);
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}