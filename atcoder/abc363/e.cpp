#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int h, w; cin >> h >> w;
    int y; cin >> y;
    vector<vector<int>> grid(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> vis(h, vector<int>(w, 0));
    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
    const pii dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
        for(auto &[dx, dy] : dirs) {
            int nx = i+dx, ny = j+dy;
            if(nx<0 || nx>=h || ny<0 || ny>=w) {
                if(!vis[i][j]) pq.push({grid[i][j], i, j});
                vis[i][j] = 1;
            }
        }
    }
    int ans = h*w;
    for(int i = 1; i <= y;i++) {
        while(!pq.empty()) {
            auto [tp, ci, cj] = pq.top();
            if(tp <= i) {
                //debug(tp, ci, cj);
                ans--;
                pq.pop();
                for(auto &[dx, dy] : dirs) {
                    int nx = ci+dx, ny = cj+dy;
                    if(nx<0 || nx>=h || ny<0 || ny>=w || vis[nx][ny]) continue;
                    //debug("push", grid[nx][ny], nx, ny);
                    pq.push({grid[nx][ny], nx, ny});
                    vis[nx][ny] = 1;
                }
            } else{
                break;
            }
        }
        cout<<ans<<nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

