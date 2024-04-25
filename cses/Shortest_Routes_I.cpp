#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pii pair<ll, ll>
#define tii tuple<ll, ll, ll>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 1001001001;
const ll INFLL = 1LL<<60;

void test_case() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<ll> vtx(n+1, INFLL);
    vtx[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while(!q.empty()){
        auto [dist, idx] = q.top(); q.pop();
        if(vtx[idx] != dist) continue;
        for(auto &[to, w]: adj[idx]){
            if(ckmin(vtx[to], vtx[idx] + w)){
                q.push({vtx[to], to});
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        cout << vtx[i] << " ";
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
