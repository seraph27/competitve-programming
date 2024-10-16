// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
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

template<typename T>
vector<T> dijkstra(int s, vector<vector<pair<int,T>>> adj){
    int n=sz(adj);
    vector<T> dis(n,INF);
    vector<int> vis(n);
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dis[s]=0,pq.push({0,s});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto &[v,w]: adj[u]) if(d+w<dis[v]){
            dis[v]=d+w;
            pq.push({dis[v],v});
        }
    }
    return dis;
}

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;
    vector<int> damage(n);
    for(auto&x: damage) cin >> x;
    vector<vector<pair<int, int>>> adj, adj2(n);
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        if(!damage[u] && !damage[v]) {
            adj2[u].pb({v, w});
            adj2[v].pb({u, w});
        }
    }
    auto dist = dijkstra<int>(a, adj);
    auto a_dist = dijkstra<int>(a, adj2);
    auto b_dist = dijkstra<int>(b, adj2);
    debug(dist, a_dist, b_dist);
    

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}


