// Problem: B - Arithmetic Progression Subsequence
// Contest: AtCoder Regular Contest 170
// URL: https://atcoder.jp/contests/arc170/tasks/arc170_b
// Time Limit: 2000
// Start: 2024/09/07 22:34:07

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

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(auto&a: vi) {
        cin >> a;
        --a;
    } 

    ll ans = 0;

    for(int l = 0; l < n; l++) {
        vector has1(10, vector<int>(10, 0));
        vector<int> has2(10, 0);
        for(int o = 0; o < 10; o++) has1[o].assign(10, 0);
        has2.assign(10, 0);

        int r = l;
        for(; r < n; r++) {
            int ok = 0;
            for(int d = -10; d <= 10; d++) {
                int c = vi[r];
                int b = c - d;
                int a = b - d;
                if(a < 0 || a >= 10) continue;
                if(has1[a][b]) {
                    ok = 1;
                    break;
                }
            }
            if(ok) break;
            int b = vi[r];
            for(int a = 0; a < 10; a++) if(has2[a]) has1[a][b] = 1;
            has2[b] = 1;

        }
        ans+=n-r;
    }
    cout<<ans<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

