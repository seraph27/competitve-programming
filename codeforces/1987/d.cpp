// Problem: D. World is Mine
// Contest: EPIC Institute of Technology Round Summer 2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1987/problem/D
// Time Limit: 2000
// Start: 2024/09/05 10:50:20

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

void shiina_mashiro() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> vi;
    for(auto &[k, v] : mp) {
        vi.pb(v);
    }

    debug(vi);
    int nn = sz(vi);
    vector dp(nn+5, vector<int>(nn+5, INF));
    dp[0][0] = 0;
    //dp[i][j] := max cakes eat by bob by the ith idx picking j cakes  //112222333444567 --> 2433111 if i pick 3 -> 4, 4 -> 6
    for(int i = 0; i <= nn; i++) {
        for(int j = 0; j <= nn; j++) {
            if(dp[i][j] + vi[i] <= i - j) {
                ckmin(dp[i+1][j+1], dp[i][j] + vi[i]);
            }
            ckmin(dp[i+1][j], dp[i][j]);
        }
    }
    int jj = nn;
    while(dp[nn][jj]==INF) jj--;

    cout << nn - jj  << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
