#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.f); cerr << ','; __print(x.s); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll INFLL = 100100100100100100;
const int INF = 1001001001;
const int mod = 1e9+7;
const char nl = '\n';

void test_case() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> coord(n+1); 
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        coord[i].first = x;
        coord[i].second = y;
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> vis(n+1, 0);
    vector<int> bounds = {-1, -1, INF, INF}; //max x, max y, min x, min y

    auto dfs = [&](auto &&dfs, int v) -> void {
        vis[v] = 1;
        pair<int, int> cd = coord[v]; 
        ckmax(bounds[0], cd.first);
        ckmax(bounds[1], cd.second);
        ckmin(bounds[2], cd.first);
        ckmin(bounds[3], cd.second);
        for(auto &a : adj[v]){
            if(!vis[a]){
                dfs(dfs, a);
            }
        }
    };

    int ans = INF;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            bounds.assign({-1, -1, INF, INF});
        } 
        dfs(dfs, i);
        int perimeter = (bounds[0]-bounds[2]) + (bounds[1]-bounds[3]);
        ckmin(ans, 2 * perimeter);
    }

    cout << ans << nl;
   
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("fenceplan.in","r",stdin); freopen("fenceplan.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
