// Problem: C - Count Order
// Contest: AtCoder Beginner Contest 150
// URL: https://atcoder.jp/contests/abc150/tasks/abc150_c
// Time Limit: 2000
// Start: 2024/08/22 10:27:31

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
    vector<int> p(n), q(n);
    for(auto&a: p) cin >> a;
    for(auto&a: q) cin >> a;
    
    vector<int> start(n);
    iota(all(start), 1);

    int pidx = -1, qidx = -1;
    int cnt = 0;
    do {
        cnt++;
        int ok = 1;
        for(int i = 0; i < n; i++) {
            if(start[i] != p[i]) {
                ok = 0;
                break;
            }
        }
        if(ok) pidx = cnt;
        int ok2 = 1;
        for(int i = 0; i < n; i++) {
            if(start[i] != q[i]) {
                ok2 = 0;
                break;
            }
        }
        if(ok2) qidx = cnt;
    } while(next_permutation(all(start)));


    cout << abs(pidx - qidx) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

