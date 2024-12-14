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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 1001001001;

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, char>>> adj(n);
    for(int i = 0; i < m; i++){
        char c; cin >> c;
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    vector<int> color(n, 0);
    vector<int> vis(n, 0);
    color[0] = 1;
    bool ok = 1;
    auto dfs = [&](auto&&dfs, int v) -> void {
        vis[v] = 1;
        for(auto&[e, tag]: adj[v]){
            int nextcolor;
            if(tag=='S') nextcolor = color[v];
            else nextcolor = (color[v] == 1 ? 2 : 1);
            if(color[e] != 0 && nextcolor != color[e]){
                ok = 0;
                break;
            }
            color[e] = nextcolor;
            if(!vis[e]){ 
                dfs(dfs, e);
            }
        }
    };

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(dfs, i);
            ans++;
        }
    }
    if(!ok) cout << 0 << nl;
    else{
        cout << 1;
        for(int j = 0; j < ans; j++){
            cout << 0;
        }
        cout << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("revegetate.in","r",stdin); freopen("revegetate.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}