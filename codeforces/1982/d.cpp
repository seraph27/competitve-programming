// Problem: D. Beauty of the mountains
// Contest: Codeforces Round 955 (Div. 2, with prizes from NEAR!)
// URL: https://codeforces.com/contest/1982/problem/D
// Time Limit: 2000
// Start: 2024/09/03 16:46:42

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

int vi[505][505];
string type[505];
ll pref0[505][505], pref1[505][505];

void shiina_mashiro() {
    int n, m, k; cin >> n >> m >> k;
    ll sum0 = 0, sum1 = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> vi[i][j];
    for(int i = 0; i < n; i++) cin >> type[i];

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        pref0[i+1][j+1] = pref0[i][j+1] + pref0[i+1][j] - pref0[i][j] + (type[i][j]-'0' ? 0 : 1);
        pref1[i+1][j+1] = pref1[i][j+1] + pref1[i+1][j] - pref1[i][j] + (type[i][j]-'0' ? 1 : 0);
        if(type[i][j]-'0') sum1+=vi[i][j];
        else sum0+=vi[i][j];
    }
    
    ll gc = 0;
    
    auto get = [&](int y1, int y2, int x1, int x2, int tp) -> ll {
        if(tp==0) return pref0[y2][x2] - pref0[y1][x2] - pref0[y2][x1] + pref0[y1][x1];
        else return pref1[y2][x2] - pref1[y1][x2] - pref1[y2][x1] + pref1[y1][x1];
    };

    for(int i = k; i <= n; i++) for(int j = k; j <= m; j++) {
        ll diff = get(i-k, i, j-k, j, 0) - get(i-k, i, j-k, j, 1);
        gc = gcd(gc, abs(diff));
    }

    ll diff = abs(sum0-sum1);
    if(gc==0 && diff!=0) {
        cout<<"No"<<nl;
        return;
    }
    
    if(gcd(gc, diff) == gc) {
        cout<<"Yes"<<nl;
    } else {
        cout<<"No"<<nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
