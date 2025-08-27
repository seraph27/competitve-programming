// Problem: Word Combinations
// Contest: CSES Problem Set
// URL: https://cses.fi/problemset/task/1731
// Time Limit: 1000
// Start: Sun Aug 24 07:55:28 2025
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

struct trie {
    static const int MX = 1e6+ 5;
    int cnt;
    int nex[MX][26];
    bool exist[MX];

    trie() { init(); }

    void init() {
        cnt = 0;
        memset(nex, -1, sizeof(nex));
        memset(exist, 0, sizeof(exist));
    }

    void insert(const string &s) {
        int vtx = 0;
        for (char c : s) {
            int d = c - 'a';
            int &nx = nex[vtx][d];
            if (nx == -1) nx = ++cnt;
            vtx = nx;
        }
        exist[vtx] = true;
    }

    string search(string &s) {
        int vtx = 0; string ans;
        for (char c : s) {
            int d = c - 'a';
            ans += c;
            int nx = nex[vtx][d];
            if (nx == -1) return s;
            vtx = nx;
            if (exist[vtx]) return ans;
        }
        return s;
    }
};

void shiina_mashiro() {
    string s; cin >> s;
    int k; cin >> k;

    trie tr;
    for(int i = 0; i < k; i++) {
        string t; cin >> t;
        tr.insert(t);
    }

    int n = sz(s);
    const int mod = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        if(!dp[i]) continue;
        int u = 0;
        for(int j = i; j < n; j++) {
            int c = s[j] - 'a';
            u = tr.nex[u][c];
            if(u==-1) break;
            if(tr.exist[u]) {
                dp[j + 1] += dp[i];
                dp[j + 1] %= mod;
            }
        }
    }
    debug(dp);
    cout << dp[n] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

