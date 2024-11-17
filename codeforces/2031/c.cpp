// Problem: C. Penchick and BBQ Buns
// Contest: Codeforces Round 987 (Div. 2)
// URL: https://codeforces.com/contest/2031/problem/C
// Time Limit: 2000
// Start: Fri Nov 15 04:52:19 2024
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

bool chksqrt(int x) {
    return isqrt(x)*isqrt(x)==x;
}
void shiina_mashiro() {
    int n; cin >> n;
    if(n%2==0) {
        int cnt = 1;
        for(int i = 0; i < n; i+=2) {
            cout << cnt << " " << cnt <<  " ";
            cnt++;
        }
        cout << nl;
        return;
    }
    vector<int> assign(n+1);
    if(n < 27) {
        cout << -1 << nl;
        return;
    } 
    vector<int> v = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 13, 12, 12, 1, 13};
    for(auto &vv : v) {
        cout << vv << " ";
    }
    int cnt = 14;
    for(int i = v.size()+1; i <= n; i+=2) {
        cout << cnt << " ";
        cout << cnt << " ";
        cnt++;
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

