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
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0)), match(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++) {
            grid[i][j] = s[j]-'0';
        }
    }
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.length(); j++) {
            match[i][j] = s[j]-'0';
        }
    }
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            if(grid[i][j] == match[i][j]) continue;
            else {
                int diff = match[i][j] - grid[i][j];
                if(diff<0) diff+=3;
                grid[i][j] += diff;
                grid[i+1][j+1] += diff;
                grid[i][j+1] += diff*2;
                grid[i+1][j] += diff*2;

                grid[i][j] %= 3;
                grid[i+1][j+1] %= 3;
                grid[i][j+1] %= 3;
                grid[i+1][j] %= 3;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != match[i][j]) {
                cout << "No" << nl;
                return;
            }
        }
    }
    cout << "Yes" << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

