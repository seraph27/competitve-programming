#include <bits/stdc++.h>
#include <atcoder/modint>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using namespace atcoder;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

using mint = modint998244353;
const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

struct trie {
    int now_sz;
    vector<ar<int, 26>> nex;
    ll ans;
    vector<int> cnt;
    ar<int, 26> def;
    trie(int len) {
        nex.reserve(len+1);
        cnt.reserve(len+1);
        def.fill(-1);
        now_sz = ans = 0;
        make_node();
    }
    
    int make_node() {
        nex.pb(def);
        cnt.pb(0);
        return now_sz++;
    }

    void insert(string &s) {
        int p = 0;
        for(int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            int &nx = nex[p][c];
            if(nx == -1) {
                nx = make_node();
            } 
            p = nx;
            ans += cnt[p]++;
        }
    }
};

void seraph() {
    trie tr(300000); 
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        tr.insert(s);
    }
    cout << tr.ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

