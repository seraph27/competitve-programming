// Problem: H - Branch Manager
// Contest: Southern California Regional 2024 - Practice Contest 1
// URL: https://vjudge.net/contest/669057#problem/H
// Time Limit: 4000
// Start: 2024/11/02 15:55:33
// mintemplate
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    vector<vector<int>> adj(n+1);
    for(int i =0; i < n-1; i++) {
        int u, v; cin >>u >> v;
        adj[u].pb(v);
    }
    for(int i = 0; i <= n; i++) sort(all(adj[i]), greater<int>());
    vector<int> dest(m);
    for(int i = 0; i < m; i++) {
        cin >> dest[i];
    }

    vector<int> parent(n+1), vis(n+1);
    auto dfs = [&](auto&&s, int u, int p) -> void{
        parent[u] = p;
        for (auto&e : adj[u]) {
            if(e != p) {
                s(s, e, u);
            }
        }
    };
    dfs(dfs, 1, -1);
    int k = 1;
    for(; adj[k].size(); k = adj[k].back()) vis[k] = 1;
    vis[k] = 1;
    vector<int> bad(n+1);
    int ans = 0;
    auto dfs2 = [&](auto&&s, int u, int p) -> void {
        bad[u] = 1;
        vis[u] = 0;
        parent[u] = -1;
        for(auto&e : adj[u]) if(e != p) {
            s(s, e, u);
            adj[e].clear();
        }
    };
    for(int i = 0; i < m; i++) {
        if(vis[dest[i]]) ans++;
        else {
            if(bad[dest[i]]) {
                cout << ans << nl;
                return;
            }
            int now = dest[i]; 
            int par = parent[now];
            while(!vis[now] && now!=1) {
                int cnt = 0;
                if(bad[par]) {
                    cout << ans << nl;
                    return;
                }
                for(auto &e : adj[par]) {
                    if(e < now) { 
                        cnt++;
                        dfs2(dfs2, e, par);
                    }
                }
                for(int j = 0; j < cnt; j++) adj[par].pop_back();
                vis[now] = 1;
                now = par;
                par = parent[now];
            }
            ans++;
            debug(vis);
        }
    }
    cout << ans << endl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
