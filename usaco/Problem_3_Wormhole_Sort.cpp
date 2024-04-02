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
    vector<int> coord(n+1); 
    vector<int> wrong;
    for(int i = 1; i <= n; i++){
        int p; cin >> p;
        coord[i] = p;
        if(i!=p) wrong.push_back(i);
    }
    vector<ar<int, 3>> cow(m+1);

    int maxwidth = 0;
    for(int i = 1; i <= m; i++){    
        int a, b, w; cin >> a >> b >> w;
        cow[i] = {w, a, b};
        ckmax(maxwidth, w);
    }
    sort(all(cow));
    if(wrong.size() == 0) {cout << -1 << nl; return;}

    int l = 0, r = maxwidth, ans = 0;
    while(l <= r){
       
        int mid = (l+r)>>1;
        debug(mid);
        vector<vector<int>> adj(n+1);
        for(int i = 1; i <= m; i++){
            if(cow[i][0] >= mid){
                adj[cow[i][1]].push_back(cow[i][2]);
                adj[cow[i][2]].push_back(cow[i][1]);
            }
        }

        vector<int> vis(n+1, 0);
        auto dfs = [&](auto &&dfs, int v) -> void {
            vis[v] = 1;
            for(auto&a: adj[v]){
                if(!vis[a]){
                    dfs(dfs, a);
                }
            }
        };
        dfs(dfs, wrong[0]);
        bool ok = 1;
        for(int i = 0; i < wrong.size(); i++){
            if(!vis[wrong[i]]) ok = 0;
        }

        if(ok) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("wormsort.in","r",stdin); freopen("wormsort.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
