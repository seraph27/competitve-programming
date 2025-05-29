// Problem: F. Goblin
// Contest: Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2106/F
// Time Limit: 2000
// Start: Tue May 20 00:12:32 2025
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
    string s; cin >> s;
    if(s == "0") {
        cout << 0 << nl;
        return;
    }
    if(s == string(n, '0')) {
        cout << (1 + n-1) * (n-1) / 2 << nl;
        return;
    }
    auto calc = [&](int l, int r, int type) -> int {
        if(type == 1) {
            int heightl = n-l-1, heightr = heightl - (r - l);
            int width = r - l + 1;
            return (heightr + heightl) * (r - l + 1) / 2;
        } else {
            int heightl = l, heightr = heightl + (r - l);
            return (heightr + heightl) * (r - l + 1) / 2;
        }
    };
    vector<pair<int, int> > v;
    for(int L = 0; L < n;) {
        if(s[L] == '0') {
            int start = L;
            while(L < n && s[L] == '0') L++;
            v.emplace_back(start, L-1);
        } else L++;
    }
    int ans = 1;
    for(auto [l, r] : v) {
        ckmax(ans, max(calc(l, r, 1), calc(l, r, 2)) + 1);
    }
    for(int i = 0; i + 1 < sz(v); i++) {
        auto [l1, r1] = v[i];
        auto [l2, r2] = v[i+1];
        if(r1 + 2 == l2) {
            ckmax(ans, calc(l1, r1, 1) + calc(l2, r2, 2) + 1);
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

