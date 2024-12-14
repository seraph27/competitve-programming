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

double calcdist(int x1, int y1, int x2, int y2){
    return sqrt(pow((y2-y1), 2) + pow((x2-x1), 2));
}

void test_case() {
    int n; cin >> n;
    vector<double> dist;
    vector<int> vx(n), vy(n);
    vector<int> vp(n);
    for(int i = 0; i < n; i++){
        int x, y, p; cin >> x >> y >> p;
        vx[i] = x; vy[i] = y;
        vp[i] = p;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                float calc = calcdist(vx[i], vy[i], vx[j], vy[j]);
                if(vp[i] >= calc) adj[i].push_back(j);
            }
        }
    }
    // for(vector<int>&aa: adj) {
    //     debug(aa);
    // }
    vector<int> vis(n, 0);
    auto dfs = [&](auto&&dfs, int v, int cnt) -> int {
        vis[v] = 1;
        for(int u: adj[v]){
            if(!vis[u]){
                cnt = dfs(dfs, u, cnt+1);
            }
        }
        return cnt;
    };

    int ans = 0;    
    for(int i = 0; i < n; i++) {
        vis.assign(n, 0);
        ckmax(ans, dfs(dfs, i, 1));
    }
    cout << ans << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("moocast.in","r",stdin); freopen("moocast.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
