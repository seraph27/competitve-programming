// Problem: D. Alice's Adventures in Cards
// Contest: Codeforces Round 986 (Div. 2)
// URL: https://codeforces.com/contest/2028/problem/D
// Time Limit: 2000
// Start: Sun Nov 10 07:35:46 2024
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
    string s = "qkj";
    vector<vector<int>> vi(3, vector<int>(n, 0));
    for(int j = 0; j < 3; j++) for (int i = 0; i < n; ++i) {
        cin >> vi[j][i];
    }
    
    vector<pair<char, int>> ans(n, {' ', -1});
    ar<int, 3> reach = {n-1, n-1, n-1};
    for(int j = n-2; j>=0; j--) {
        int idx = -1;
        for(int o = 0; o < 3; o++) {
            if(vi[o][reach[o]] < vi[o][j]) {
                idx = o;
                break;
            }
        }
        if(idx == -1) continue;
        ans[j] = {s[idx], reach[idx]};
        for(int o = 0; o < 3; o++) {
            if(vi[o][reach[o]] > vi[o][j]) {
                reach[o] = j;
            }
        }
    }   
    if(ans[0].second == -1) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
    vector<pair<char, int>> ans2({ans[0]});
    while(ans2.back().second != -1) {
        ans2.push_back(ans[ans2.back().second]);
    }
    ans2.pop_back();
    debug(ans2);
    cout << sz(ans2) << nl;
    for(auto [c, i] : ans2) cout << c << " " << i+1 << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

