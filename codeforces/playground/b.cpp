// Problem: B. Warehouse
// Contest: Codeforces Beta Round 35 (Div. 2)
// URL: https://codeforces.com/contest/35/problem/B
// Time Limit: 2000
// Start: Wed Jul 23 02:22:24 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
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
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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
    int n, m; cin >> n >> m;
    int q; cin >> q;
    bool vis[30][30];
    memset(vis, 0, sizeof vis);
    
    map<string, pii> mp;
    for(int i = 0; i < q; i++) {
        string type; cin >> type;
        if(type == "+1") {
            int x, y; cin >> x >> y;
            string s; cin >> s;
            --x; --y;
            int ok = 0;
            for(int j = x; j < n; j++) {
                for(int k = (j==x ? y : 0); k < m; k++) {
                    if(!vis[j][k]) {
                        mp[s] = {j, k};
                        vis[j][k] = 1;
                        ok = 1;
                        break;
                    }
                }
                if(ok) break;
            }
        } else {
            string s; cin >> s;
            if(!mp.count(s) || mp[s].first == -1) {
                cout << -1 << " " << -1 << nl;
            } else {
                vis[mp[s].first][mp[s].second] = 0;
                cout << mp[s].first + 1 << " " << mp[s].second + 1<< nl;
            }
            mp[s] = {-1, -1};
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.in","r",stdin); freopen("output.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

