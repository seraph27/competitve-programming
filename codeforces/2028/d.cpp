// Problem: D. Alice's Adventures in Cards
// Contest: Codeforces Round 986 (Div. 2)
// URL: https://codeforces.com/contest/2028/problem/D
// Time Limit: 2000
// Start: Sun Nov 10 07:35:46 2024
// mintemplate
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

#ifdef MISAKA
struct _debug {
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
    int n;
    cin >> n;
    vector<int> q(n), k(n), j(n);
    vector<vector<int>> pos(3, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        pos[0][q[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        pos[1][k[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> j[i];
        pos[2][j[i]] = i;
    }

    vector<vector<int>> adj(n + 1);
    for (int x = 1; x <= n; ++x) {
        for (int p = 0; p < 3; ++p) {
            for (int y = 1; y <= n; ++y) {
                if (pos[p][x] > pos[p][y]) {
                    adj[x].pb(y);
                }
            }
        }
    }

    vector<int> dist(n + 1, -1);
    queue<int> qd;
    dist[1] = 0;
    qd.push(1);
    while (!qd.empty()) {
        int u = qd.front();
        qd.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                qd.push(v);
            }
        }
    }

    if (dist[n] == -1) {
        cout << -1 << nl;
    } else {
        vector<int> path;
        for (int x = n; x != 1; ) {
            path.pb(x);
            for (int v : adj[x]) {
                if (dist[v] == dist[x] - 1) {
                    x = v;
                    break;
                }
            }
        }
        path.pb(1);
        reverse(all(path));
        for (int x : path) cout << x << ' ';
        cout << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
