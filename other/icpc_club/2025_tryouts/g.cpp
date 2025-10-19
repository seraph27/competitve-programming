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
#define eb emplace_back
#define db double

using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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

void solve() {
    int n, k; cin >> n >> k;

    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> ships(k);
    for(int i = 0; i < k; i++) cin >> ships[i];
    sort(all(ships), greater<int>());
    
    auto check = [&](int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < n;
    };

    auto ok = [&]() -> bool {
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'O') return false;
        }
        return true;
    };
    int ans = 0;

    auto dfs = [&](auto&&s, int ship_id) -> void {
        if(ship_id == k) {
            if(ok()) {
                ans++;
            }
            return;
        }
        int len = ships[ship_id];
        
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            if(grid[i][j] == 'X' || grid[i][j] == 'D') continue;
            bool can = true;
            pii pos = {-1, -1};
            //D = done
            for(int d = 0; d < len; d++) {
                if(!check(i, j + d) || grid[i][j + d] == 'X' || grid[i][j + d] == 'D') {
                    pos = {i, j};
                    can = false;
                    break;
                }
            }
            if(can) {
                ar<char, 5> save;
                for(int d = 0; d < len; d++) {
                    save[d] = grid[i][j + d];
                    grid[i][j + d] = 'D';
                }
                s(s, ship_id + 1);
                for(int d = 0; d < len; d++) {
                    grid[i][j + d] = save[d];
                }
            }

            if(len == 1) continue;
            can = true;
            pos = {-1, -1};
            for(int d = 0; d < len; d++) {
                if(!check(i + d, j) || grid[i + d][j] == 'X' || grid[i + d][j] == 'D') {
                    pos = {i, j};
                    can = false;
                    break;
                }
            }
            if(can) {
                ar<char, 5> save;
                for(int d = 0; d < len; d++) {
                    save[d] = grid[i + d][j];
                    grid[i + d][j] = 'D';
                }
                s(s, ship_id + 1);
                for(int d = 0; d < len; d++) {
                    grid[i + d][j] = save[d];
                }
            }
        }
    };

    dfs(dfs, 0);
    cout << ans << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
