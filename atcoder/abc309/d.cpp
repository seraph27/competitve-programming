// Problem: D - Add One Edge
// Contest: デンソークリエイトプログラミングコンテスト2023（AtCoder Beginner Contest 309）
// URL: https://atcoder.jp/contests/abc309/tasks/abc309_d
// Time Limit: 2000
// Start: 2024/10/23 18:01:08
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
vector<T> dijkstra(int start, vector<vector<pair<int,T>>> &adj){
    int n=sz(adj);
    vector<T> dist(n,4e18); //change if needed
    priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> pq;
    dist[start]=0, pq.push({0,start});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto &[v,w]: adj[u]) if(ckmin(dist[v],d+w)){
            pq.push({dist[v],v});
        }
    }
    return dist;
}

void shiina_mashiro() {
    int n1, n2, m; cin >> n1 >> n2 >> m;
    vector<vector<pair<int, ll>>> adj(n1+n2);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb({v, 1});
        adj[v].pb({u, 1});
    }
    auto dis1 = dijkstra<ll>(0, adj), dis2 = dijkstra<ll>(n1+n2-1, adj);
    ll mx1 = 0, mx2 = 0;
    for(auto &x : dis1) if(x < 2e18) ckmax(mx1, x);
    for(auto &x : dis2) if(x < 2e18) ckmax(mx2, x);
    cout << mx1 + mx2 + 1 << nl;


}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

