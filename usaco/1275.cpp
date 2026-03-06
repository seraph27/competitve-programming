// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// codeforces
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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> vi(n);
    for(auto &x : vi) {
        cin >> x;
        --x;
    }

    vector<pair<int, int>> ans;
    int g = 0, h = 0;
    int lg = n-1, lh = n-1;
    for(; g < n; g++) if(s[g] == 'G') break;
    for(; h < n; h++) if(s[h] == 'H') break;
    for(; lg >= 0; lg--) if(s[lg] == 'G') break;
    for(; lh >= 0; lh--) if(s[lh] == 'H') break;
    for(char c : {'G', 'H'}) {
        int idx = 0; 
        for(; idx < n; idx++) if(s[idx] == c) break;
        if(c == 'G' && vi[idx] < lg) continue;
        if(c == 'H' && vi[idx] < lh) continue;

        //idx is now including all
        for(int j = idx - 1; j >= 0; j--) {
            auto other = (c == 'G') ? 'H' : 'G';
            if(s[j] == other && vi[j] >= idx) ans.pb({min(j, idx), max(j, idx)});
        }
    }
    if(g + vi[g] >= lg && h + vi[h] >= lh) ans.pb({min(g, h), max(g, h)});
    sort_unique(ans);
    cout << sz(ans) << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

