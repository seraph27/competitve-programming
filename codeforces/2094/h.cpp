// Problem: H. La Vaca Saturno Saturnita
// Contest: Codeforces Round 1017 (Div. 4)
// URL: https://codeforces.com/contest/2094/problem/H
// Time Limit: 4000
// Start: 2025/04/16 15:13:46
// mintemplate
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
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

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<int> vi(n);
    map<int, vector<int>> mp;
    for(auto&a: vi) cin >> a;

    for(int i = 0; i < n; i++) {
        mp[vi[i]].pb(i);
    }

    auto fac = [&](int x) -> vector<int> {
        vector<int> res;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                res.push_back(i);
                if (i * i != x) res.push_back(x / i);
            }
        }
        return res;
    };
    while(q--) {
        int k, l, r; cin >> k >> l >> r;
        --l; --r;
        auto get = fac(k);
        vector<pair<int, int>> divs;
        for(int i = 0; i < sz(get); i++) {
            auto it = lower_bound(all(mp[get[i]]), l);
            if(it != mp[get[i]].end() && *it <= r) {
                divs.pb({*it, get[i]});
            }
        }
        sort(all(divs));
        int ans = 0, lst = l;
        for(auto&[a, b] : divs) {
            ans+=k * (a-lst);
            lst = a;
            while(k%b==0) {
                k/=b;
            }
        }
        ans+= k*(r-lst+1);
        cout << ans << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

