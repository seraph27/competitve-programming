// Problem: D - 2017-like Number
// Contest: AtCoder Beginner Contest 084
// URL: https://atcoder.jp/contests/abc084/tasks/abc084_d
// Time Limit: 2000
// Start: 2024/09/18 13:30:10

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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

vector<int> vi;

vector<int> sieve() {
    vector<int> vis(1e5+5, 0);
    vector<int> res;
    for(int i = 2; i < 1e5+1; i++) {
        if(!vis[i]) {
            res.pb(i);
            for(int j = i; j < 1e5+5; j+=i) {
                vis[j] = 1;
            } 
        }
    }
    return res;
}
void init() {
    auto primes = sieve();
    sort(all(primes));
    for(int i = 3; i < 1e5+5; i+=2) {
        int fi = i, se = (i+1)/2;
        auto it = lower_bound(all(primes), fi);
        auto it2 = lower_bound(all(primes), se);
        if(it != primes.end() && fi == *it && it2 != primes.end() && se==*it2) {
            vi.pb(fi);
        }
    }
}
void shiina_mashiro() {
    init();
    int q; cin >> q;
    for(;q--;) {
        int l, r; cin >> l >> r;
        auto i1 = upper_bound(all(vi), r);
        auto i2 = lower_bound(all(vi), l);
        cout << i1-i2 << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

