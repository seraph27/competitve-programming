// Problem: E. Changing the String
// Contest: Educational Codeforces Round 179 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2111/problem/E
// Time Limit: 2000
// Start: Tue Jun  3 09:06:12 2025
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

set<int> S[4];
void shiina_mashiro() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for(int i = 0; i < q; i++) {
        string a, b; cin >> a >> b;
        if(a+b == "ba") {
            S[0].insert(i);
        } else if(a+b == "ca") {
            S[1].insert(i);
        } else if(a+b == "bc") {
            S[2].insert(i);
        } else if(a+b == "cb") {
            S[3].insert(i);
        }
    }

    for(int i = 0; i < n; i++) {
        if(s[i] == 'b') {
            if(!S[0].empty()) {
                S[0].erase(S[0].begin());
                s[i] = 'a';
                continue;
            } 
            if(!S[2].empty() && !S[1].empty()) {
                auto it = S[2].begin();
                auto it2 = S[1].lower_bound(*it);
                if(it2 == S[1].end()) continue;
                s[i] = 'a';
                S[2].erase(S[2].begin());
                S[1].erase(it2);
                continue;
            }
        } else if(s[i] == 'c') {
            if(!S[1].empty()) {
                S[1].erase(S[1].begin());
                s[i] = 'a';
                continue;
            }
            if(!S[3].empty()) {
                auto it = S[3].begin();
                auto it2 = S[0].lower_bound(*it);
                if(it2 == S[0].end()) {
                    s[i] = 'b';
                    S[3].erase(S[3].begin());
                    continue;
                }
                s[i] = 'a';
                S[3].erase(S[3].begin());
                S[0].erase(it2);
                continue;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        S[i].clear();
    }
    cout << s << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

