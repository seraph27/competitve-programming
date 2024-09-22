// Problem: E. Alternating String
// Contest: Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/E
// Time Limit: 2000
// Start: 2024/09/01 22:41:43

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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

int L[2<<17][26][2], R[2<<17][26][2];
void shiina_mashiro() {
    int n; cin >> n;
    string s; cin >> s;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 26; j++) for(int k = 0; k < 2; k++) {
            L[i+1][j][k] = L[i][j][k];
        }
        L[i+1][s[i]-'a'][i%2]++;
    }
    for(int j = 0; j < 26; j++) for(int k = 0; k < 2; k++) R[n][j][k] = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) for(int k = 0; k < 2; k++) {
            R[i][j][k] = R[i+1][j][k];
        }
        R[i][s[i]-'a'][i%2]++;
    }

    int ans = 1e9;
    if(n%2 == 0) {
        for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++) {
            ckmin(ans, n - L[n][j][0] - L[n][k][1]);
        }
    } else {
        for(int i = 0; i < n; i++) for(int j = 0; j < 26; j++) for(int k = 0; k < 26; k++) {
            ckmin(ans, n - (L[i][j][0] + R[i+1][j][1]) - (L[i][k][1] + R[i+1][k][0]));
        }
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
