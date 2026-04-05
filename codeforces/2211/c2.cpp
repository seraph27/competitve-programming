
// Problem: C2. Equal Multisets (Easy Version)
// Contest: Nebius Round 2 (Codeforces Round 1088, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2211/problem/C1
// Time Limit: 2000
// Start: Sat Mar 28 12:38:16 2026
// multitest
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
#define eb emplace_back
#define db double

using namespace std;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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

    vector<int> a(n), b(n);
    for(auto&x : a) cin >> x;
    for(auto&x : b) cin >> x;

    bool ok = true;
    for(int i = 0; i < k; i++) {
        int j = i + k;
        for(; j < n; j += k) {
            if(a[j - k] == a[j]) {
                if(b[j - k] != -1 && b[j] != -1 && b[j - k] != b[j]) ok = false;
                if(b[j] != -1) b[j - k] = b[j];
                if(b[j - k] != -1) b[j] = b[j - k];
            } else {
                if(b[j - k] != -1 && b[j - k] != a[j - k]) ok = false;
                if(b[j] != -1 && b[j] != a[j]) ok = false;
                b[j - k] = a[j - k];
                b[j] = a[j];
            }
        }

        j -= k;
        for(; j >= i + k; j -= k) {
            if(a[j] == a[j - k]) {
                if(b[j] != -1) b[j - k] = b[j];
            }
        }
    }
    int wild = 0;
    map<int, int> mp;
    for(int i = 0; i < k; i++) {
        wild += (b[i] == -1);
        mp[a[i]]++;
        mp[b[i]]--;
    }

    for(auto &[k, v] : mp) {
        if(k == -1) continue;
        if(v < 0) {
            ok = false;
        } else {
            wild -= v;
        }
    }
    cout << (ok && wild == 0 ? "YES" : "NO") << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
