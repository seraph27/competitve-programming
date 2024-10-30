// Problem: D. Sums of Segments
// Contest: Educational Codeforces Round 171 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2026/problem/D
// Time Limit: 4000
// Start: Mon Oct 28 07:36:01 2024
// mintemplate
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
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    vector<ll> vi(n);
    for (int i = 0; i < n; i++) cin >> vi[i];
    
    vector<ll> pref(n+1), pref2(n+1), pref3(n+1), pref4(n+1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + vi[i-1];
        pref2[i] = pref2[i-1] + pref[i];
    }
    pref3[1] = pref2[n];
    for(int i = 2; i <= n; i++) {
        pref3[i] = pref3[i-1] - (i-2>=0 ? vi[i-2] * (n-i+2) : 0);
    }
    for(int i = 1; i <= n; i++) {
        pref4[i] = pref4[i-1] + pref3[i];
    }
    vector<ll> prefidx(n+1);
    for(int i = 1; i <= n; i++) {
        prefidx[i]+=prefidx[i-1]+n-i+1;
    }
    auto idx = [&](ll x) {
        auto res = lower_bound(all(prefidx), x) - prefidx.begin(); //1-idx 
        return res;
    };
    auto solve = [&](ll x) -> ll {
        ll ans = 0;
        auto w = idx(x);
        if(!w) return 0;
        ll over = prefidx[w] - x;
        ans += (over ? pref4[w-1] : pref4[w]);
        if(over) {
            ans += (pref2[n-over] - pref2[w-1]);
            debug(ans, pref2[n-over], pref2[w-1], pref2);
            ans -= (pref[w-1] * ((n-over)-(w-1)));
            debug(ans, pref[w-1], (n-over)-(w-1));
        }
        debug(ans);
        return ans;
    };
    int q; cin >> q;
    for(;q--;) {
        ll l, r; cin >> l >> r;
        cout << solve(r) - solve(l-1) << nl;
    }
    debug(pref, pref2, pref3);
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

