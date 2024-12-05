// Problem: D. Move Back at a Cost
// Contest: Codeforces Round 990 (Div. 2)
// URL: https://codeforces.com/contest/2047/problem/D
// Time Limit: 2000
// Start: Tue Dec  3 00:42:45 2024
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
    vector<pair<int, int>> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i].first;
        vi[i].second = i;
    }
    auto op = [&](const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    };
    auto temp = vi;
    sort(all(vi), op);
    int curr = 0;
    vector<int> ans, vis(n);
    int mn = 1e18;
    for(int i = 0; i < n; i++) {
        if(vi[i].second < curr) {
            while(i+1<n && vi[i+1].first == vi[i].first) {
                i++;
                if(vi[i].second > curr) {
                    curr = vi[i].second;
                    ans.pb(vi[i].first);
                    vis[vi[i].second] = 1;
                }
            }
            mn = vi[i].first;
            break;
        }
        curr = vi[i].second;
        ans.pb(vi[i].first);
        vis[curr] = 1;
    }
    debug(vis);
    debug(curr, mn);
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        if(temp[i].first == mn+1 && i > curr) ans.pb(temp[i].first);
        else ans.pb(temp[i].first+1);
    }
    sort(all(ans));
    for(auto&x: ans) {
        cout << x << ' ';
    }
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

