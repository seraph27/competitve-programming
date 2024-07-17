#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    const int SZ = n+2;
    int dp[1<<SZ][n+1];
    for(int i = 0; i < 1<<SZ; i++) for(int j = 0; j < n+1; j++) dp[i][j] = INF;
    queue<pii> q;
    int start = 0;
    for(int i = 0; i < n; i++) if(s[i]=='B') start|=(1<<i);
    dp[start][n] = 0;
    q.push({start, n});
    while(!q.empty()) {
        auto [curr, empt] = q.front(); q.pop();
        for(int i = 0; i < n+1; i++) {
            if(abs(i-empt)>1) {
                int newpos = curr;
                if((curr>>i)&1) {
                    newpos |= (1<<empt);
                    newpos ^= (1<<i);
                }
                if((curr>>i+1)&1) {
                    newpos |= (1<<empt+1);
                    newpos ^= (1<<i+1);
                }
                if(ckmin(dp[newpos][i], dp[curr][empt] + 1)) q.push({newpos, i});
            }
        }
    }
    int end = 0;
    for(int i = 0; i < n; i++) if(t[i]=='B') end|=(1<<i);
    cout << (dp[end][n] == INF ? -1 : dp[end][n]) << nl;

}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

