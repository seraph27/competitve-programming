// Problem: D1. Turtle and a MEX Problem (Easy Version)
// Contest: Codeforces Round 968 (Div. 2)
// URL: https://codeforces.com/contest/2003/problem/D1
// Time Limit: 2000
// Start: 2024/08/25 22:37:05

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
    int n, m; cin >> n >> m;
    int mex = 0;
    for(int i = 0; i < n; i++) {
        int len; cin >> len;
        vector<int> vi;
        set<int> s;
        for(int k = 0; k < len; k++) {
            int x; cin >> x;
            s.insert(x);
        }
        
        int now = 0, flag = 0;
        while(s.count(now) || !flag) {
            if(!s.count(now)) {
                flag = 1;
            }
            now++;
        }
        ckmax(mex, now);
    }

    debug(mex);
    ll ans = 0;
    debug(min(mex, m+1));
    ans += min(mex+1, m+1) * (ll)mex;
    debug(ans);
    if(mex < m) {
        ans+=(ll)(mex+1 + m) * (m-mex) / 2;
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
