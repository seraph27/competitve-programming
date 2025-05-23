// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// codeforces
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

int maxXOR(int x, int m) {
    int y = 0;
    for (int bit = 61; bit >= 0; --bit) {
        int mask = (1LL << bit);
        if ((y | mask) <= m && (((x ^ y) & mask) == 0)) {
            y |= mask;
        }
    }
    return x ^ y;
}
void shiina_mashiro() {
    int x, m; cin >> x >> m;
    int ans = 0;
    if(x==1) {
        cout << m << nl;
        return;
    }
    for(int i = 1; i <= min(m, x); i++) {
        int res = x ^ i;
        if(res%i== 0) {
            debug(x, m, i, res);
            ans++;
        }
    }
    auto get = maxXOR(x, m);
    debug(ans);
    debug(get);
    int div = ifloor(get, x);
    int cnt = 0;
    bool ok = 0;
    int mx = (int)4e18;
    for(int i = min(mx, div*x); i > 0; i-=x) {
        debug(x^i);
        if((x^i) > m) ans--;
        cnt++;
        if(cnt > 1000) break;
    }
    cout << ans+div-1 << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

