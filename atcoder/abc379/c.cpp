// Problem: C - Sowing Stones
// Contest: トヨタ自動車プログラミングコンテスト2024#11(AtCoder Beginner Contest 379)
// URL: https://atcoder.jp/contests/abc379/tasks/abc379_c
// Time Limit: 2000
// Start: 2024/11/29 14:25:25
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
    int n, m; cin >> n >> m;
    vector<int> x(m), a(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<int> idx(m);
    iota(all(idx), 0);
    sort(all(idx), [&](auto p, auto q) {return x[p] < x[q];});
    vector<int> nx(m), na(m);
    for(int i = 0; i < m; i++) {
        nx[i] = x[idx[i]];
        na[i] = a[idx[i]];
    }
    x = nx;
    a = na;
    int ans = 0;
    int back = n;
    for(int i = m-1; ~i; i--) {
        int diff = back - x[i];
        if(diff >= a[i]) {
            back-=a[i];
            ans+=(diff + (diff-a[i]+1)) * a[i]/2;
        } else {
            if(a[i]-diff>1) {
                cout << -1 << nl;
                return;
            }
            back = x[i]-1;
            ans+=(diff+1) * diff/2;
        }
    }
    if(back>0) {
        cout << -1 << nl;
        return;
    } 
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

