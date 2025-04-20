// Problem: C. Wonderful City
// Contest: Neowise Labs Contest 1 (Codeforces Round 1018, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2096/problem/C
// Time Limit: 2000
// Start: 2025/04/19 8:17:59
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> g[i][j];
    }

    vector<int> c_row(n), c_col(n);
    for(auto&a : c_row) cin >> a;
    for(auto&a: c_col) cin >> a;

    vector<ar<int, 4>> okR(n-1, ar<int, 4>{1, 1, 1, 1});
    vector<ar<int, 4>> okC(n-1, ar<int, 4>{1, 1, 1, 1});
    
    for(int i = 0; i < n-1; i++) for(int j = 0; j < n; j++){
        int diffR = g[i+1][j] - g[i][j];
        if(diffR ==0) {
            okR[i][0] = 0, okR[i][3] = 0;
        } else if(diffR == 1) {
            okR[i][2] = 0;
        } else if(diffR == -1){
            okR[i][1] = 0;
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < n-1; j++){
        int diffC = g[i][j+1] - g[i][j];
        if(diffC == 0) {
            okC[j][0] = 0, okC[j][3] = 0;
        } else if(diffC == 1) {
            okC[j][2] = 0; //can't add left side (1 2) -> cancel 2nd bit 
        } else if(diffC == -1){
            okC[j][1] = 0;
        }
    }

    int mx = 4e18;
    ar<int, 2> dpR{0, c_row[0]}; //buy flip or nah
    for(int i = 0; i < n-1; i++) {
        ar<int, 2> ndpR = {mx, mx};
        for(int k = 0; k < 4; k++) {
            if(!okR[i][k]) continue;
            int x = (k&3)>>1, y = k&1;
            ckmin(ndpR[y], dpR[x] + (y ? c_row[i+1] : 0));
        }
        swap(dpR, ndpR);
    }
    int ansR = min(dpR[0], dpR[1]);
    ar<int, 2> dpC{0, c_col[0]}; 
    for(int i = 0; i < n-1; i++) {
        ar<int, 2> ndpC = {mx, mx};
        for(int k = 0; k < 4; k++) {
            if(!okC[i][k]) continue;
            int x = (k&3)>>1, y = k&1;
            ckmin(ndpC[y], dpC[x] + (y ? c_col[i+1] : 0));
        }
        swap(dpC, ndpC);
    }
    int ansC = min(dpC[0], dpC[1]);

    cout << ((ansR>2e18 || ansC>2e18) ? -1 : ansR+ansC) << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

