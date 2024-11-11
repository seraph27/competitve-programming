// Problem: E. Reverse the Rivers
// Contest: Codeforces Round 984 (Div. 3)
// URL: https://codeforces.com/contest/2036/problem/E
// Time Limit: 2000
// Start: Sat Nov  2 08:51:57 2024
// mintemplate
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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> g(k);
    for(int i = 0; i < n; i++) for(int j = 0; j < k; j++) {
        int x; cin >> x;
        g[j].pb(x | (g[j].size() ? g[j].back() : 0));
    } //row is region col is country 

    auto bin_search = [&](int region, int value, int type) -> int{
        if(type==0) { // < 
            auto it = lower_bound(g[region].begin(), g[region].end(), value);
            if(it != g[region].begin()) it--;
            return *it < value ? it - g[region].begin() : -1;
        } else { // > 
            auto it = upper_bound(g[region].begin(), g[region].end(), value);
            return (it != g[region].end() && *it > value) ? it - g[region].begin() : n;
        }
    };
    debug(g);
    for(;q--;) {
        int m; cin >> m;
        int l = 0, r = n-1;
        for(int i = 0; i < m; i++) {
            int reg, val;
            char sign;
            cin >> reg >> sign >> val;
            reg--;
            if(sign == '<') {
                int pos = bin_search(reg, val, 0);
                if(pos != -1) ckmin(r, pos);
                else r = -1;
            } else {
                int pos = bin_search(reg, val, 1);
                if(pos != n) ckmax(l, pos);
                else l = n;
            }
        }
        if(l <= r) cout << l+1 << nl;
        else cout << -1 << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

