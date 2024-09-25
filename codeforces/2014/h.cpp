// Problem: H. Robin Hood Archery
// Contest: Codeforces Round 974 (Div. 3)
// URL: https://codeforces.com/contest/2014/problem/H
// Time Limit: 3000
// Start: 2024/09/22 19:44:37

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
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

vector<unsigned long long> rg(1e6+5);
void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<ll> vi(n);
    for(auto&a: vi) cin >> a;
    vector<ll> pref(n+1);
    for(int i = 0; i < n; i++) pref[i+1]=pref[i]^rg[vi[i]];
    for(;q--;) {
        int l, r; cin >> l >> r;
        if((pref[r]^pref[l-1])==0) cout << "Yes" << nl;
        else cout << "No" << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    for(int i = 0; i < 1e6+5; i++) {
        rg[i] = rng();
    }
    while (t--) shiina_mashiro();
}
