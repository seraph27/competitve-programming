// Problem: D. Sharky Surfing
// Contest: Codeforces Round 988 (Div. 3)
// URL: https://codeforces.com/contest/2037/problem/D
// Time Limit: 3000
// Start: Sun Nov 17 06:58:36 2024
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
    int n, m, l; cin >> n >> m >> l;
    vector<ar<int, 2>> bounds(n);
    for(int i = 0; i < n; i++) cin >> bounds[i][0] >> bounds[i][1];
    vector<ar<int, 2>> power(m);
    for(int i = 0; i < m; i++) cin >> power[i][0] >> power[i][1];
    priority_queue<int> pq;
    int currval = 1, ans = 0;
    int idxp = 0;
    for(int i = 0; i < n; i++) {
        int need = bounds[i][1] - bounds[i][0] + 2;
        while(idxp < m && power[idxp][0] < bounds[i][0]) {
            pq.push(power[idxp][1]);
            idxp++;
        }
        while(currval < need && !pq.empty()) {
            debug(need, pq.top());
            auto tp = pq.top(); pq.pop();
            ans++;
            currval += tp;
        }
        if(currval < need) {
            cout << -1 << nl;
            return;
        }
    }
    cout << ans << nl;
    
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
