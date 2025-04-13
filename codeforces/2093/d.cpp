// Problem: D. Skibidi Table
// Contest: Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/contest/2093/problem/D
// Time Limit: 1000
// Start: 2025/04/08 22:58:27
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

    auto calc_num = [&](int x, int y) {
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int s = (x >> i) & 1, t = (y >> i) & 1, d;
            if (s == 0 && t == 0)
                d = 0;
            else if (s == 1 && t == 1)
                d = 1;
            else if (s == 1 && t == 0)
                d = 2;
            else
                d = 3;
            ans = ans * 4 + d;
        }
        return ans + 1;
    };
    auto calc_coord = [&](int val) {
        int x = 0, y = 0;
        vector<int> digits(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            digits[i] = val % 4;
            val /= 4;
        }
        debug(digits);
        for (int i = 0; i < n; i++) {
            int digit = digits[i];
            x = (x << 1) | ((digit == 0 || digit == 3) ? 0 : 1);
            y = (y << 1) | ((digit == 0 || digit == 2) ? 0 : 1);
        }
        return make_pair(x, y);
    };
    int q; cin >> q;
    while(q--) {
        string s; cin >> s;
        if(s == "->") {
            int x, y; cin >> x >> y;
            --x; --y;
            cout << calc_num(x, y) << nl;
        } else {
            int x; cin >> x;
            --x;
            auto [one, two] = calc_coord(x);
            cout << one+1 << " " << two+1 << nl;
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

