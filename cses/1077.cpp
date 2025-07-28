// Problem: Sliding Window Cost
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1077
// Time Limit: 1000
// Start: Thu Jul 24 18:44:07 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
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
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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
   int n, k; cin >> n >> k;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    vector<int> pref(n+1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + vi[i-1];
    }
    multiset<int> s1, s2;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++) {
        if(s1.empty() || vi[i] < *s1.rbegin()) s1.insert(vi[i]), sum1+=vi[i];
        else s2.insert(vi[i]), sum2+=vi[i];
        if(i>=k) {
            bool removed = 0;
            if(s1.find(vi[i-k]) != s1.end()) {
                s1.erase(s1.find(vi[i-k])), sum1-=vi[i-k];
                removed = 1;
            } 
            if(s2.find(vi[i-k]) != s2.end() && !removed) {
                s2.erase(s2.find(vi[i-k])), sum2-=vi[i-k];
            }
        }
        if(sz(s1)-sz(s2) > 1) {
            auto b = *s1.rbegin();
            s1.erase(s1.find(b)), sum1-=b;
            s2.insert(b), sum2+=b;
        } else if(sz(s2) - sz(s1) > 1) {
            auto b = *s2.begin();
            s2.erase(s2.find(b)), sum2-=b;
            s1.insert(b), sum1+=b;
        }
        if(i>=k-1) {
            int med;
            if(sz(s1) >= sz(s2)) {
                med = *s1.rbegin();
            } else {
                med = *s2.begin();
            }
            cout << (med * sz(s1) - sum1) + (sum2 - med * sz(s2)) << " ";
        }
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

