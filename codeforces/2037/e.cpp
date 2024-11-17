// Problem: E. Kachina's Favorite Binary String
// Contest: Codeforces Round 988 (Div. 3)
// URL: https://codeforces.com/contest/2037/problem/E
// Time Limit: 2000
// Start: Sun Nov 17 08:06:11 2024
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
    int n; cin >> n;
    int L = 0, R = 1;
    auto ask = [&](int l, int r) {
        cout << "? " << l+1 << " " << r+1 << endl;
        int x; cin >> x;
        return x;
    };
    if(n==1) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    vector<int> ans(n, 1);
    auto last = 0;
    int zero = 0, one = 0;
    int lastzero = -1;
    while(R<n) {
        auto get = ask(L, R);
        if(R == n-1 && get == 0) {
            cout << "! IMPOSSIBLE" << endl;
            return;
        }
        if(get > last) {
            //3 - 1*1 = 2; 
            auto bef = (get-last)-(zero*one);
            zero+=bef;
            one++;
            debug(bef);
            for(int i = R-bef; i<R; i++) ans[i] = 0;
            ckmax(lastzero, R-1);
        } else {
            ckmax(lastzero, R-1);
            if(R==n-1) {
                auto get = ask(lastzero, n-1);
                if(get != n-1-lastzero) {
                    ans[n-1] = 0;
                } 
            }
        }
        last = get;
        R++;
    }
    cout << "! ";
    for(int i=0; i<n; i++) cout << ans[i];
    cout << endl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

