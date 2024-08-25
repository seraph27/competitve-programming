// Problem: B - 105
// Contest: AtCoder Beginner Contest 106
// URL: https://atcoder.jp/contests/abc106/tasks/abc106_b
// Time Limit: 2000
// Start: 2024/08/19 14:59:54

#include <bits/stdc++.h>
#define sz(x) x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
    int x; cin >> x;

    auto solve = [&](int n) -> int{
        int ans = 1;
        for(int i = 2; i*i <= n; i++) {
            if(n%i == 0) {
                int e = 1;
                while(n%i==0) {
                    e++;
                    n/=i;
                }
                ans *= e;
            }
        }
        if(n>1) ans*=2; 
        debug(ans);

        return ans;
    };

    int ans2 = 0;
    for(int i = 1; i <= x; i+=2) {
        if(solve(i) == 8) {
            ans2++;
        }
    }
    cout << ans2 << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

