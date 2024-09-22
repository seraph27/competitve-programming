// Problem: A - Chmax Rush!
// Contest: AtCoder Regular Contest 182
// URL: https://atcoder.jp/contests/arc182/tasks/arc182_a
// Time Limit: 2000
// Start: 2024/09/07 14:04:40

#include <bits/stdc++.h>
#include <atcoder/modint>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
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
using mint = modint998244353;

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> vp(q), vq(q);
    for(int i = 0; i < q; i++) {
        cin >> vp[i] >> vq[i];
    }
    
    vector<int> vis(q, 0);
    auto change = [&](int pos, int x) -> bool {
        if(vis[pos] != 0 && vis[pos]!=x) {
            return false;
        } else{
            vis[pos]=x;
        }
        return true;
    };
    mint ans = 1;
    for(int i = 0; i < q; i++) for(int j = i+1; j < q; j++) {
        if(vq[i] <= vq[j]) continue;
        else {
            if(vp[i]==vp[j]) {
                cout << 0 << nl;
                return;
            } else if(vp[i] > vp[j]) {
                if(!change(i, 1) or !change(j, -1)) {
                    cout<<0<<nl;
                    return;
                }
            } else {
                if(!change(i, -1) or !change(j, 1)) {
                    cout << 0 << nl;
                    return;
                }
            }
        }
    } 
    debug(vis);
    for(int i = 0; i < q; i++) {
        if(vis[i]==0) ans*=2;
    }
    cout << ans.val() << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

