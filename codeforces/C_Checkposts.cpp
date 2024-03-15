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

const int mxN = 1e5+1;
vector<int> adj[mxN], radj[mxN];
bool vis1[mxN], vis2[mxN];
int who[mxN];
vector<int> stk;

void dfs1(int u){
    vis1[u] = true;
    for(int v : adj[u]){ 
        if(!vis1[v]){
            dfs1(v);
        }
        
    }
    stk.push_back(u);
}
void dfs2(int u, int rep){
    vis2[u] = true;
    who[u] = rep;
    for(int v : radj[u]){
        if(!vis2[v]){
            dfs2(v, rep);
        }         
    }
}

void test_case() {
    int n; cin >> n;
    vector<int> costs(n);
    for(auto&a: costs) cin >> a;
    int m; cin >> m; //edges
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){ 
        if(!vis1[i]) dfs1(i);
    }
    while(stk.size() > 0){
        int tt = stk.back();
        stk.pop_back();
        if(!vis2[tt]) dfs2(tt, tt);
    }
    for(int i = 1; i <= n; i++){
        if(who[i] == 0){
            who[i] = i;
        }
    }   
    vector<int> big(n+5, INT_MAX);
    vector<multiset<int>> ms(n+5);
    for(int i = 1; i <= n; i++){
        ckmin(big[who[i]], costs[i-1]);
        ms[who[i]].insert(costs[i-1]);
    }
    ll mincosts = 0;
    ll minposts = 1;
    for(int i = 1; i <= n; i++){
        if(i == who[i]){
            mincosts += (big[i] != INT_MAX) ? big[i] : 0;
            int xx = ms[i].count(*(ms[i].begin()));
            minposts *= (xx != 0) ? xx : 1;
            minposts %= mod;
        }

    }
    cout << mincosts << " " << minposts;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
