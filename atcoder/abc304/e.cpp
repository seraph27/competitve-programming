// Problem: E - Good Graph
// Contest: 東京海上日動プログラミングコンテスト2023（AtCoder Beginner Contest 304）
// URL: https://atcoder.jp/contests/abc304/tasks/abc304_e
// Time Limit: 3000
// Start: 2024/09/07 3:28:58

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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
const int INF = 0x3f3f3f3f;

struct DSU {
    vector<int> p, size;

    DSU(int n) {
        p.resize(n);
        size.resize(n, 1);
        iota(all(p), 0);
    }
    
    int find(int x) {
        return p[x]==x ? x : (p[x] = find(p[x]));
    }

    bool same(int x, int y) {
        return find(x)==find(y);
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x!=y) {
            if(x<y) swap(x, y);
            p[y] = x;
            size[x]+=size[y];
        }
    }
};
void shiina_mashiro() {
    int n, m; cin >> n >> m;

    DSU uf(n);

    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u;--v;
        uf.merge(u, v);
    }
    int k; cin >> k;
    set<ar<int, 2>> s;
    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        --x;--y;
        s.insert({uf.find(x), uf.find(y)});
    }
    debug(s);
    int q; cin >> q;
    for(;q--;) {
        int a, b; cin >> a >> b;
        --a;--b;
        if(s.count({uf.find(a), uf.find(b)}) || s.count({uf.find(b), uf.find(a)})) {
            cout << "No" << nl;
        } else {
            cout << "Yes" << nl;
        }
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

