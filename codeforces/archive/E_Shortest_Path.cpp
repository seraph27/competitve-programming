#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
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
const ll INFLL = 1LL<<60;

void test_case() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<ll>> adj(n+1);
    vector<vector<ll>> vtx(n+1, vector<ll>(n+1, INFLL));
    vector<vector<ll>> path(n+1, vector<ll>(n+1, -1));
    set<ar<ll, 3>> forbid;
    vtx[1][0] = 0; //vtx[i][j]:= current node = i such that previous node is j
 
    for(int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < k; i++){
        ll a, b, c; cin >> a >> b >> c;
        forbid.insert({a, b, c});
    }
    priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
    pq.push({0, 1, 0}); //dist, idx, from

    while(!pq.empty()){
        auto [dist, idx, from] = pq.top(); pq.pop();
        if(vtx[idx][from] != dist) continue;
        for(auto &to: adj[idx]){
            if(forbid.count({from, idx, to})) continue;
            if(ckmin(vtx[to][idx], vtx[idx][from] + 1)){ 
                path[to][idx] = from;
                pq.push({vtx[to][idx], to, idx});
            }
        }
    }
  
    vector<int> ans;
    ll best = INFLL; 
    int bestidx = 0;
    //debug(path);
    for(int i = 1; i < n+1; i++){
        if(vtx[n][i] != INFLL && ckmin(best, vtx[n][i])) bestidx = i;
    }
    if(best == INFLL) {cout << -1 << nl; return;}

    int curr = n, last = bestidx;
    ans.push_back(curr);
    for(;last!=1;){
        int temp = path[curr][last];
        curr=last, last = temp;
        ans.push_back(curr);
    }
    ans.push_back(last);

    cout << ans.size() -1 << nl;
    for(int i = ans.size()-1; ~i ;i--){
        cout << ans[i] << " ";
    }
    cout << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
