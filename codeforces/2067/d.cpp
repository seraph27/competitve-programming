// Problem: D. Object Identification
// Contest: Codeforces Round 1004 (Div. 2)
// URL: https://codeforces.com/contest/2067/problem/D
// Time Limit: 2000
// Start: 2025/02/17 23:11:29
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
    vector<int> vi(n);
    vector<bool> has(n+1, 0);
    int mn = 1e9, mx = -1;
    int idx1, idx2;
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
        has[vi[i]] = 1;
        if(ckmin(mn, vi[i])) idx1 = i+1;
        if(ckmax(mx, vi[i])) idx2 = i+1;
    }
    assert(idx1 != idx2);
    auto ask = [&](int fi, int se) -> int {
        cout << "? " << fi << ' ' << se << endl;
        int res; cin >> res;
        return res;
    };
    for(int i = 1; i <= n; i++) {
        if(!has[i]) {
            int v1 = ask(i, i+1>n?1:i+1);
            if(v1 == 0) {
                cout << "! A" << endl;
                return;
            } else {
                cout << "! B" << endl;
                return;
            }
        }
    }

    int v1 = ask(idx1, idx2);
    int v2 = ask(idx2, idx1);
    if(v1 == 0 || v2 == 0 || v1 != v2) {
        cout << "! A" << endl;
        return;
    }
    if(v1+v2>n || v1>=n-1 || v2 >= n-1) {
        cout << "! B" << endl;
        return;
    }
    cout << "! A" << endl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

