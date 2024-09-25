// Problem: A - Appraiser
// Contest: AtCoder Regular Contest 184
// URL: https://atcoder.jp/contests/arc184/tasks/arc184_a
// Time Limit: 2000
// Start: 2024/09/23 15:47:38

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
    int n, m, q; cin >> n >> m >> q;
    
    int queries = 0;
    auto ask = [&](int c1, int c2) -> int {
        queries++;
        assert(c1>=1 && c1 <= n && c2 >= 1 && c2 <=n);
        cout << "? " << c1 << " " << c2 << endl;
        int res; cin >> res;
        return res;
    };
    
    set<int> real, fake;
    set<int> rn, fn;
    int now = 1;
    for(int i = 1; i <= n; i++) {
        if(i==now) {
            rn.emplace(i);
            continue;
        }
        int ret = ask(now, i);
        if(!ret) rn.emplace(i);
        else fn.emplace(i);

        if(rn.size()==11 || fn.size()==11) {
            if(fn.size() > rn.size()) swap(fn, rn);
            for(auto &c : rn) real.emplace(c);
            for(auto &c2 : fn) fake.emplace(c2);
            rn.clear();
            fn.clear();
            now = i+1;
        }
        debug(real, fake, rn, fn, now, i);
    }
    if(rn.size()) {
        if(!ask(*real.begin(), *rn.begin())) {
            for(auto&c : rn) real.emplace(c);
        } else for(auto&c2 : rn) fake.emplace(c2);
    } 
    if(fn.size()) {
        if(!ask(*real.begin(), *fn.begin())) {
            for(auto&c : fn) real.emplace(c); 
        } else for(auto &c2 : fn) fake.emplace(c2);
    }
    debug(queries);
    cout << "!";
    for(auto &c : fake) {
        cout << " " << c;
    }
    cout << endl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

