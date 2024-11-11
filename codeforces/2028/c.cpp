// Problem: C. Alice's Adventures in Cutting Cake
// Contest: Codeforces Round 986 (Div. 2)
// URL: https://codeforces.com/contest/2028/problem/C
// Time Limit: 2000
// Start: Sun Nov 10 07:35:46 2024
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
    int n, m, v; cin >> n >> m >> v;
    vector<int> vi(n);
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    map<int, int> L, R;
    int sumL = 0, sumR = 0;
    int cntL = 0, cntR = 0;
    for (int i = 0; i < n; i++) {
        sumL += vi[i];
        if(sumL >= v) {
            sumL = 0;
            cntL++;
            L[cntL] = i;
        }
    }
    L[0] = -1;
    for(int i = n-1; i >= 0; i--) {
        sumR += vi[i];
        if(sumR >= v) {
            sumR = 0;
            cntR++;
            R[cntR] = i;
        }
    }
    R[0] = n;
    int ans = -1;
    vector<int> pref(n+1);
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + vi[i];
    }
    debug(L, R);
    for(int i = 0; i <= m; i++) {
        auto Lpos = L.lower_bound(i);
        auto Rpos = R.lower_bound(m-i);
        if(Lpos == L.end() || Rpos == R.end()) continue;
        auto lpos = Lpos->second;
        auto rpos = Rpos->second;
        if(lpos > rpos) continue;
        int add = pref[rpos] - pref[lpos+1];
        debug(add);
        ckmax(ans, add);
    }
    debug(ans);
    if(ans==-1) {
        cout << -1 << nl;
        return;
    }
    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

