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
    vector<vector<int>> radj(n+1);
    vector<int> vis1(n+1, 0);
    vector<int> vis2(n+1, 0);
    vector<int> who(n+1);
    vector<int> stk;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    auto dfs1 = [&](auto &&dfs1, int v) -> void {
        vis1[v] = 1;
        for(auto&a: adj[v]) {
            if(!vis1[a]){
                dfs1(dfs1, a);
            }
        }
        stk.push_back(v);
    };

    auto dfs2 = [&](auto &&dfs2, int v, int rep) -> void {
        vis2[v] = 1;
        who[v] = rep;
        for(auto&a: radj[v]) {
            if(!vis2[a]){
                dfs2(dfs2, a, rep);
            }
        }
    };

    for(int i = 1; i <= n; i++){
        if(!vis1[i]) dfs1(dfs1, i);
    }

    while(stk.size() > 0){
        debug(vis2);
        int b = stk.back();
        stk.pop_back();
        if(!vis2[b]) dfs2(dfs2, b, b);
    }
    debug(who);
    // if(n==4 && m==4){
    //     cout << "NO" << nl;
    //     cout << 1 << " " << 3 << nl;
    //     return;
    // }
    
    for(int i = 1; i <= n; i++){
        for (int u : adj[i]) {
            if (who[i] != who[u]) { 
                cout << "NO" << nl;
                cout << u << " " << i << '\n';
                return;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if (who[i] != who[1]) { 
            cout << "NO" << nl;
            cout << 1 << " " << i << '\n';
            return;
        }  
    }
    cout << "YES" << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
