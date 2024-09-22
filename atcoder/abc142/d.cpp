// Problem: D - Disjoint Set of Common Divisors
// Contest: AtCoder Beginner Contest 142
// URL: https://atcoder.jp/contests/abc142/tasks/abc142_d
// Time Limit: 2000
// Start: 2024/09/11 12:18:35

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

vector<ll> f(ll n) {
    vector<ll> res;
    ll i = 1;
    for(; i*i < n; i++) {
        if(n%i==0) {
            res.pb(i);
            res.pb(n/i);
        }
    }
    if(i*i==n) res.pb(i);
    return res;
}
void shiina_mashiro() {
    ll a, b; cin >> a >> b;
    ll gd = gcd(a, b);
    auto vi = f(gd);
    sort(all(vi));
    vector<ll> ans;
    for(ll i = 0; i < sz(vi); i++) {
        ll ok = 1;
        for(ll j = 0; j < sz(ans); j++) {
            if(gcd(ans[j], vi[i]) != 1) {
                ok = 0;
                break;
            }
        }
        if(ok) ans.pb(vi[i]);
    }
    cout << ans.size() << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

