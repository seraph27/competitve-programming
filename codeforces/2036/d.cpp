// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// codeforces
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
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    const int maxlayer = min(n, m)/2;
    debug(maxlayer);
    vector<vector<char>> layer(maxlayer+1);
    int cs = 0, rs = 0, ce = n-1, re = m-1;
    for(int i = 0; i < maxlayer; i++) {
        for(int j = rs; j <= re; j++) {
            layer[i].pb(grid[rs][j]);
        }
        for(int j = cs+1; j <= ce; j++) {
            layer[i].pb(grid[j][re]);
        }
        for(int j = re-1; j >= rs; j--) {
            layer[i].pb(grid[ce][j]);
        }
        for(int j = ce-1; j >= cs; j--) {
            layer[i].pb(grid[j][cs]);
        }
        rs++, cs++, re--, ce--;
    }
    ll ans = 0;
    for(int i = 0; i < maxlayer; i++) {
        layer[i].pop_back();
        for(int j = 0; j < 3; j++) {
            layer[i].pb(layer[i][j]);
        }
        for(int j = 0; j < sz(layer[i])-3; j++) {
            debug(j);
            if(layer[i][j] == '1' && layer[i][j+1] == '5' && layer[i][j+2] == '4' && layer[i][j+3] == '3') {
                ans++;
            }
        }
    }
    cout << ans << nl;
    debug(layer);
  
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

