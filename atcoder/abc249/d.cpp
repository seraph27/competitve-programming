// Problem: D - Index Trio
// Contest: モノグサプログラミングコンテスト2022（AtCoder Beginner Contest 249）
// URL: https://atcoder.jp/contests/abc249/tasks/abc249_d
// Time Limit: 2000
// Start: 2024/09/19 12:46:00

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

vector<int> facs (int x) {
    vector<int> res;
    int i = 1;
    for(; i * i < x; i++) {
        if(x%i==0) {
            res.pb(i);
            res.pb(x/i);
        }
    }
    if(i * i == x) res.pb(i);
    return res;
}
void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(2e5+5, 0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vi[x]++;
    }
    ll ans = 0;
    for(int i = 1; i < 2e5+5; i++) {
        if(!vi[i]) continue; 
        auto get = facs(i);
        debug(get);
        for(auto &f : get) {
            ans+= (ll)vi[i] * vi[f] * vi[i/f];
        }
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

