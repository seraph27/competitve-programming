// Problem: Planets Cycles
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1751
// Time Limit: 1000
// Start: Wed Jul  2 03:50:18 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif

const char nl = '\n';

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> to(n);
    vector<int> indeg(n, 0);
    vector<vector<int>> rev(n);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        --x;
        to[i] = x;
        rev[x].pb(i);
        indeg[x]++;
    }

    queue<int> bfs;
    for(int i = 0; i < n; i++) {
        if(!indeg[i]) bfs.push(i);
    }
    while(!bfs.empty()) {
        auto f = bfs.front(); bfs.pop();
        int nxt = to[f];
        indeg[nxt]--;
        if(indeg[nxt] == 0) bfs.push(nxt);
    }

    vector<int> vis(n, 0);
    vector<vector<int>> cycles;
    vector<int> siz(n, -1);
    for(int i = 0; i < n; i++) {
        vector<int> cyc;
        if(!vis[i] && indeg[i] == 1) {
            for(auto cur = i; !vis[cur]; cur = to[cur]) {
                vis[cur] = 1;
                cyc.pb(cur);
            }
        }
        if(sz(cyc)) {
            for(auto x : cyc) siz[x] = sz(cyc);
            cycles.pb(cyc);
        }
    }

    queue<int> bfs2;
    for(int i = 0; i < n; i++) {
        if(vis[i]) bfs2.push(i);
    }
    while(!bfs2.empty()) {
        auto f = bfs2.front(); bfs2.pop();
        for(auto &e : rev[f]) {
            if(siz[e] == -1) {
                siz[e] = siz[f] + 1;
            }
            if(!vis[e]) bfs2.push(e);
        }
    }
    for(auto x : siz) cout << x << " ";
    cout << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

