#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 1001001001;

void seraph() {
    int n; cin >> n;
    vector<string> grid;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        grid.push_back(s);
    }

    ar<int, 4> dx = {-1, 1, 0, 0}; ar<int, 4> dy = {0, 0, -1, 1};
    vector<vector<int>> vis(n, vector<int>(n, 0));

    int area = 1, perimeter = 4;
    auto dfs = [&](auto&&dfs, int x, int y) -> void {
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n || grid[nx][ny] == '.') continue;
            if(!vis[nx][ny]){
                area++;
                int sides = 4;
                for(int j = 0; j < 2; j++){
                    int sx = nx+dx[j];
                    if(sx>=0 && sx<n && vis[sx][ny]) sides-=2;
                }
                for(int k = 2; k < 4; k++){
                    int sy = ny+dy[k]; 
                    if(sy>=0 && sy<n && vis[nx][sy]) sides-=2;
                }
                perimeter+=sides;             
                dfs(dfs, nx, ny);
            } 
        }   
    };

    int maxarea = -1;
    int minperi = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j] && grid[i][j] == '#') {
                area = 1;
                perimeter = 4;
                dfs(dfs, i, j);
                if(ckmax(maxarea, area)) minperi = perimeter;
                else if(maxarea == area) ckmin(minperi, perimeter);
            }
        }
    }
    cout << maxarea << " " << minperi << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}