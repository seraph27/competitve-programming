// Problem: E - Min of Restricted Sum
// Contest: AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_e
// Time Limit: 3000
// Start: 2025/03/29 17:31:38
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
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<int> xorr(n, -1);

    
    vector<int> vis(n);
    bool bad = 0;
    auto dfs = [&](auto &&s, int u) -> void {
        vis[u] = 1;
        for(auto &[e, w] : adj[u]){
            if(xorr[e] != -1 && xorr[e] != (xorr[u] ^ w)) {
                bad = 1;
                return;
            }
            if(!vis[e]) {
                xorr[e] = xorr[u] ^ w;
                s(s, e);
            }
        }
    };

    for(int i = 0; i < n; i++) if(!vis[i]) {
        xorr[i] = 0;
        dfs(dfs, i);
    }

    if(bad) {
        cout << -1 << nl;
        return;
    }

    for(int i = 0; i < 31; i++) {
        int ones = 0, zeros = 0;
        vector<int> vis2(n);
        vector<int> vis3(n);
        auto dfs2 = [&](auto &&s, int u, int flag) -> void {
            if(!flag)vis2[u] = 1;
            else vis3[u] = 1;
            if(xorr[u] & (1 << i)) ones++;
            else zeros++;
            if(flag) {
                xorr[u] ^= (1 << i);
            }
            for(auto &[e, w] : adj[u]) {
                if(!flag && !vis2[e]) {
                    s(s, e, flag);
                }
                else if(flag && !vis3[e]) {
                    s(s, e, flag);
                }
            }
        };

        for(int j = 0; j < n; j++) if(!vis2[j]) {
            ones = 0, zeros = 0;
            dfs2(dfs2, j, 0);
            if(ones > zeros) {
                dfs2(dfs2, j, 1);
            }
        }
    }
    for(auto &x : xorr) cout << x << ' ';
    cout << nl;
     
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

