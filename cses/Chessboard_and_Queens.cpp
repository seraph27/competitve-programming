// Problem: Chessboard and Queens
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1624
// Time Limit: 1000
// Start: 2024/09/10 21:00:09

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
    vector<string> grid(8);
    for(int i = 0; i < 8; i++) cin >> grid[i];
    
    auto chk = [&](int y, int x) -> bool {
        if(grid[y][x] == '*') return false;
        for(int i = 0; i < 8; i++) {
            if(i != x && grid[y][i] == 'Q') return false;
            if(i != y && grid[i][x] == 'Q') return false;
        }
        for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) {
            if((i + j == x + y) && grid[i][j] == 'Q' && (i!=y || j != x)) return false;
        }
        for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) {
            if((i - j == y - x) && grid[i][j] == 'Q' && (i!=y || j != x)) return false;
        }
        return true;
    };
    
    int ans = 0;
    auto solve = [&](auto&&s, int cnt) -> void {
        if(cnt == 8) {
            ans++;
            return;
        }
        for(int i = 0; i < 8; i++) {
            debug(chk(cnt, i));
            if(chk(cnt, i)) {    
                if(grid[cnt][i] == '.') grid[cnt][i] = 'Q';
                s(s, cnt + 1);
                if(grid[cnt][i] == 'Q') grid[cnt][i] = '.';
            }
        }
    };

    solve(solve, 0);
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

