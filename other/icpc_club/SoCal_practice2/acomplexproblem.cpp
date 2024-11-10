#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define fi first 
#define se second
using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for(auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ')';}
template<typename T, typename... V> 
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ",", _print(v...); else cerr << "]\n"; }}; 
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else 
#define debug(x...)
#endif
vector<int> val, comp, z, cont;
int Time, ncomps;
template<vector<vector<int>>, vector<int>> int dfs(int j, G& g, F &f) {
    int low = val[j] = ++Time, x; z.pb(j);
    for(auto e : g[j]) if(comp[e] < 0) {
        low = min(low, val[e] ?: dfs(e, g, f));
    }
    if(low == val[j]) {
        do {
            x = z.back(); z.pop_back();
            comp[x] = ncomps;
            cont.pb(x);
        } while(x != j);
        f(cont); cont.clear();
        ncomps++;
    }
    return val[j] = low
}
template<vector<vector<int>>, vector<int>> void scc(G&g, F f) {
    int n = sz(g);
    val.assign(n, 0); comp.assign(n, -1);
    Time = ncomps = 0;
    for(int i = 0; i < n; i++) if(comp[i] < 0) dfs(i, g, f);
}

void solve() {
    int m, n; cin >> m >> n;
    vector<ar<string, 2>> dotted, solid;
    set<string> s;
    for(int i = 0; i < m; i++) {
        string s1, s2; cin >> s1 >> s2;
        s.insert(s1);
        s.insert(s2);
        dotted[i][0] = s1;
        dotted[i][1] = s2;
    }
    for(int i = 0; i < n; i++) {
        string s1, s2; cin >> s1 >> s2;
        s.insert(s1);
        s.insert(s2);
        solid[i][0] = s1;
        solid[i][1] = s2;
    }
    int cnt = 0;
    map<string, int> mp;
    for(auto &x : s) {
        mp[x] = cnt;
        cnt++;
    }

    vector<vector<int>> adj1(m+n);
    for(int i = 0; i < m; i++) {
        auto one = mp[dotted[i][0]];
        auto two = mp[dotted[i][1]]
        adj1[one].pb(two);
    }
    for(int i = 0; i < n; i++) {
        auto one = mp[solid[i][0]];
        auto two = mp[solid[i][1]]
        adj1[one].pb(two);
    }

    vector<vector<int>> adj2(m+n);
    for(int)




}

signed main() {
    int t = 1;
    while(t--) {
        solve();
    }
}