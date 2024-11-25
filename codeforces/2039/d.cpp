// Problem: D. Shohag Loves GCD
// Contest: CodeTON Round 9 (Div. 1 + Div. 2, Rated, Prizes!)
// URL: https://codeforces.com/contest/2039/problem/D
// Time Limit: 2000
// Start: Sat Nov 23 09:01:57 2024
// mintemplate
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n/i && n/i != n) factors.push_back(n / i);
        }
    }
    return factors;
}
void shiina_mashiro() {
    int n, m; cin >> n >> m;
    vector<int> vi(m);
    for(auto&x: vi) cin >> x;
    sort(all(vi), greater<int>());
    vector<int> ans(n+1);
    ans[1] = 0;
    for(int i = 1; i <= n; i++) {
        auto get = findFactors(i);
        int mn = 0;
        for(auto x : get){
            ckmax(mn, ans[x]);
        }
        ans[i] = mn + 1;
        if(mn+1 > m) {
            cout << -1 << nl;
            return;
        }
    }
    for(int i = 1; i <= n; i++) ans[i] = vi[ans[i]-1];
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i==n];
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

