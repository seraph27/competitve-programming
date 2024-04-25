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

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    vector<ar<ll, 2>> vtx(n+1, {INFLL, INFLL});
    vtx[1] = {0, 0};

    struct Dogshit{
        ll idx;
        bool used;
        ll dist;
    };
    auto cmp = [&](const Dogshit &a, const Dogshit &b) {return a.dist > b.dist;};
    priority_queue<Dogshit, vector<Dogshit>, decltype(cmp)> q(cmp);
    q.push({1LL, 0, 0LL});
    while(!q.empty()){
        auto [idx, used, dist] = q.top(); q.pop();
        ll curr = vtx[idx][used];
        if(curr != dist) continue;
        for(auto [to, w] : adj[idx]){
            if(!used) if(ckmin(vtx[to][1], curr + w/2)) q.push(Dogshit{to, true, vtx[to][1]});
            if(ckmin(vtx[to][used], curr + w)) q.push(Dogshit{to, used, vtx[to][used]});
        }
    }
    cout << vtx[n][1] << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
