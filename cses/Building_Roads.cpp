#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pb push_back
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

const int mod = 1e9+7;
const char nl = '\n';

void test_case() {
    int n, m; cin >> n >> m; 
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<bool> vis(n, 0);
    auto dfs = [&](auto&& self, int v) -> void {
        vis[v] = 1;
        for(auto& u : adj[v]) {
            if(!vis[u]) {
                self(self, u);
            }
        }
    };

    vector<int> points;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(dfs, i);
            ans++;
            points.pb(i);
        }
    }
    cout << ans-1 << nl;
    for(int i = 0; i < points.size()-1; i++){
        cout << points[i] << " " << points[i+1] << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
