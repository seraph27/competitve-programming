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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 1001001001;

void test_case() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<int> vtx(n, INF);
    vector<int> path(n, -1);
    vtx[0] = 0;
    vector<bool> vis(n, false);

    for(int i = 0; i < m ; i++){
        int a, b, w; cin >> a >> b >> w;
        --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    for(int i = 0; i < n; i++){
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!vis[j] && (v == -1 || vtx[j] < vtx[v])){
                v = j;
            }
        }

        if(vtx[v] == INF) break;
        vis[v] = 1;
        for(auto&e: adj[v]){
            int to = e.first;
            int w = e.second;
            if(ckmax(vtx[to], vtx[v]+w)){
                path[to] = v;
            }
        }
    }
    debug(path);
    vector<int> ans;
    for (int v = n; v != 0; v = path[v])
        ans.push_back(v+1);
    ans.push_back(1);
    for(int i = n-1; i>=0; i--){
        cout << ans[i] << " ";
    }
    cout << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}
