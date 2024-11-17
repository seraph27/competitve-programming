// problem: c. superultra's favorite permutation
// contest: codeforces round 988 (div. 3)
// url: https://codeforces.com/contest/2037/problem/c
// time limit: 2000
// start: sun nov 17 06:45:04 2024
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
template<typename t> bool ckmin(t &a, const t &b) { return a > b ? a = b, 1 : 0; }
template<typename t> bool ckmax(t &a, const t &b) { return a < b ? a = b, 1 : 0; }
template<typename t, typename s> constexpr t ifloor(const t a, const s b){return a/b-(a%b&&(a^b)<0);}
template<typename t, typename s> constexpr t iceil(const t a, const s b){return ifloor(a+b-1,b);}
template<typename t> t isqrt(const t &x){t y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename t>
void sort_unique(vector<t> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

#ifdef misaka
struct _debug {
template<typename t> static void __print(const t &x) {
    if constexpr (is_convertible_v<t, string> || is_fundamental_v<t>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename t, typename v>
static void __print(const pair<t, v> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename t, typename... v>
static void _print(const t& t, const v&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif

const char nl = '\n';

void shiina_mashiro() {
    int n; cin >> n;
    if(n<=4) {
        cout << -1 << nl;
        return;
    }
    for(int i = 1; i <= n; i+=2) {
        if(i==5) continue;
        cout << i << " ";
    }
    cout << 5 << " " << 4 << " ";
    for(int i = 2; i <= n; i+=2) {
        if(i==4) continue;
        cout << i << " ";
    }
    cout << nl;
}   

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

