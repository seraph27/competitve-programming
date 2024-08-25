// Problem: 8 Queens Problem
// Contest: ALDS1 - ALDS1_13_A
// URL: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=en
// Time Limit: 1000
// Start: 2024/08/22 10:50:22

//minimal template
#include <bits/stdc++.h>
#define sz(x) x.size()
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
    vector<string> board(8, "........");
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        board[a][b] = 'Q';
    }

    auto bounds = [&](int val) -> bool {
        if(val >= 0 && val < 8) return true;
        return false;
    };

    auto check = [&](int row, int col) -> bool {
        debug(row, col);
        for(int l = 0; l < 8; l++) {
            if(l != col && board[row][l] != '.') {debug("hori"); return false;}
            if(l != row && board[l][col] != '.') {debug("vert"); return false;} //check vertical
            int diagr = row + l, diagc = col + l;
            int edge = min(row, col);
            if(diagr-edge != row && diagc-edge != col && bounds(diagr-edge) && bounds(diagc-edge) && board[diagr-edge][diagc-edge] != '.') {
                debug("diag1");
                return false;
            }
            int diag2r = row - l, diag2c = col + l;
            int edge2 = min(8-row, col);
            if(diag2r+edge2 != row && diag2c-edge2 != col && bounds(diag2r+edge2) && bounds(diag2c-edge2) && board[diag2r+edge2][diag2c-edge2] != '.') {
                debug("diag2");
                return false; 
            }
        }
        return true;
    };

    auto rec = [&](auto&&s, int cnt) -> void {
        if(cnt == 8) {
            for(int r = 0; r < 8; r++) {
                for(int c = 0; c < 8; c++) {
                    cout << (board[r][c] == '.' ? '.' : 'Q');
                }
                cout << nl;
            }
            return;
        }
        
        for(int i = 0; i < 8; i++) {
            if(check(cnt, i) || board[cnt][i] == 'Q') {
                if(board[cnt][i] == '.') board[cnt][i] = 'X';
                s(s, cnt+1);
                if(board[cnt][i] == 'X') board[cnt][i] = '.';
            }
        }
    };
    rec(rec, 0);
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

