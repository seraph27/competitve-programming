// Problem: C - Routing
// Contest: AtCoder Regular Contest 177
// URL: https://atcoder.jp/contests/arc177/tasks/arc177_c
// Time Limit: 2500
// Start: 2024/09/06 23:53:45

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    
    int ans = 0;
    const pii dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> vis(n*n, 0);
    auto solve = [&](int type) -> void { // 0 == red 1 == blue
        priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>> > pq;
        if(type==0) pq.push({0, 0, 0});
        else pq.push({0, 0, n-1});
        vis.assign(n*n, 0);
        while(!pq.empty()) {
            auto [val, y, x] = pq.top(); pq.pop();
            if(vis[y*n + x]) continue;
            vis[y*n + x] = 1;
            if(type==0 && y==n-1 && x==n-1) {
                ans+=val;
                break;
            }
            if(type==1 && y==n-1 && x==0) {
                ans+=val;
                break;
            }
            for(auto &[dy, dx] : dirs) {
                int ny = dy + y, nx = dx + x;
                if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if(type==0) pq.push({g[ny][nx]=='R' ? val : val+1, ny, nx});
                else {
                    pq.push({g[ny][nx]=='B' ? val : val+1, ny, nx});
                }
            }
        }
    };
    solve(0);
    solve(1);
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

