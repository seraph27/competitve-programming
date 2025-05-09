// Problem: C. Action Figures
// Contest: Educational Codeforces Round 171 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2026/problem/C
// Time Limit: 2500
// Start: Mon Oct 28 07:36:01 2024
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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> vis(n), white; //black pos
    set<int> black;
    ll cost = 0;
    for(int i = 0; i < n; i++) {
        if(s[i]=='1') {
            black.insert(i);
        }
        else {
            white.pb(i);
            cost += i+1; //white need to add anyways;
        }
    }
    for(auto &x : white | views::reverse) {
        debug(black);
        auto it = black.end();
        if(it != black.begin() && x < *prev(it)) {
            vis[*prev(it)] = 1;
            black.erase(prev(it));
        } else continue;
    }
    debug(vis);
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && s[i]=='1') cnt++;
    }
    debug(cost);
    cnt = (cnt+1)/2;
    debug(cnt);
    for(int i = 0; i < n; i++) {
        if(s[i]=='1') {
            cost += i+1;
            cnt--;
        }
        if(cnt<=0) break;
    }
    cout << cost << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

