// Problem: D. Swap Dilemma
// Contest: Codeforces Round 956 (Div. 2) and ByteRace 2024
// URL: https://codeforces.com/contest/1983/problem/D
// Time Limit: 1000
// Start: 2024/08/30 0:22:48

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
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];  
        a[i]--;
    } 
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    } 

    auto va = a;
    auto vb = b;
    sort(all(va));
    sort(all(vb));

    if(va!=vb) {
        cout<<"NO"<<nl;
        return;
    }

    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(all(va), a[i]) - va.begin();
        b[i] = lower_bound(all(vb), b[i]) - vb.begin();
    }

    debug(a, b);
    auto par = [&](vector<int>&v) -> int {
        int n = sz(v);
        vector<int> vis(n);
        int p = n%2;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            p^=1;
            for(int j = v[i]; j!=i; j = v[j]) {
                vis[j] = 1;
                debug(vis, j, i, v);
            }
        }
        return p;
    };

    if(par(a) != par(b)) cout << "NO" << nl;
    else cout<<"YES"<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
