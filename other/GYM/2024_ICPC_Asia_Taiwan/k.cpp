// Problem: K. Kingdom's Development Plan
// Contest: 2024 ICPC Asia Taiwan Online Programming Contest
// URL: https://codeforces.com/gym/105383/problem/K
// Time Limit: 2000
// Start: Sun Oct 20 00:31:10 2024
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
    vector<int> indeg(n+1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;
    }
    vector<int> color(n+1);
    function<bool(int)> dfs = [&](int u) -> bool {
        color[u] = 1;
        for(int v : adj[u]) {
            if(color[v]==0) {
                if(dfs(v)) return true;
            }
            else if(color[v]==1) {
                return true;
            }
        }
        color[u] = 2;
        return false;
    };
    bool has_cycle = false;
    for(int i = 1; i <= n; i++) {
        if(!color[i]) {
            if(dfs(i)) {
                has_cycle = true;
                break;
            } 
        }
    }
    if(has_cycle) {
        cout << "IMPOSSIBLE" << nl;
        return;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int vertex = 1; vertex <= n; vertex++) {
        if(indeg[vertex]==0) {
            pq.push(vertex);
        }
    }

    vector<int> topo;
    while(!pq.empty()) {
        int tp = pq.top(); pq.pop();
        topo.pb(tp);
        for(int v : adj[tp]) {
            indeg[v]--;
            if(indeg[v]==0) {
                pq.push(v);
            }
        }
    }
    for(int i = 0; i < sz(topo); i++) {
        cout << topo[i] << " ";
    }
} 

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

