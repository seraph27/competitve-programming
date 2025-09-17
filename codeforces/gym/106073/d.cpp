// Problem: D. Dominoes
// Contest: The 2025 ICPC South America - Brazil First Phase
// URL: https://codeforces.com/gym/106073/problem/D
// Time Limit: 1500
// Start: Tue Sep 16 18:12:43 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

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
    int n; cin >> n;
    vector<pii> vi(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        vi[i] = {a, b};
    }
    
    unordered_set<int> can;
    unordered_set<int> vis;
    auto f = [&](int msk, int l, int r) -> int {
        int a = (l == -1) ? 7 : l, b = (r == -1) ? 7 : r;
        if(a > b) swap(a, b);
        return ((msk << 6 | a << 3 | b));
    };
    vector<int> l, r;
    auto dfs = [&](auto&&s, int msk, int l, int r) -> void {
        if(!vis.insert(f(msk, l, r)).second) return;
        for(int i = 0; i < n; i++) if(!((msk >> i) & 1)) {
            int nmsk = msk | (1 << i);
            int x = vi[i].first, y = vi[i].second;
            if(l == -1 || r == -1) {
                can.insert(nmsk);
                s(s, nmsk, x, y);
            }
            if(l != -1 && y == l) { can.insert(nmsk); s(s, nmsk, x, r); }
            if(l != -1 && x == l) { can.insert(nmsk); s(s, nmsk, y, r); }
            if(r != -1 && x == r) { can.insert(nmsk); s(s, nmsk, l, y); }
            if(r != -1 && y == r) { can.insert(nmsk); s(s, nmsk, l, x); }
        }
    };
    dfs(dfs, 0, -1, -1);
    cout << sz(can) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

