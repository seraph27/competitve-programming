// Problem: B - AtCoder Market
// Contest: square869120Contest #6
// URL: https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b
// Time Limit: 1000
// Start: 2024/08/20 17:16:11

//minimal template
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
    int n; cin >> n;
    vector<int> va(n), vb(n);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        va[i] = a; vb[i] = b;
    }
    ll sum = 0;
    for(int i = 0; i < n; i++) sum += abs(va[i] - vb[i]);
    sort(all(va));
    sort(all(vb));
    int mda = va[(va.size()-1)/2];
    int mdb = vb[(vb.size()-1)/2];
    for(int i = 0; i < n; i++) {
        sum += abs(va[i] - mda);
        sum += abs(vb[i] - mdb);
    }
    cout << sum << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

