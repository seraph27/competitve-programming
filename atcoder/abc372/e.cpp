// Problem: E - K-th Largest Connected Components
// Contest: ユニークビジョンプログラミングコンテスト2024 秋（AtCoder Beginner Contest 372）
// URL: https://atcoder.jp/contests/abc372/tasks/abc372_e
// Time Limit: 2000
// Start: 2024/09/21 21:00:24

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
    vector<int> f, siz;
    vector<vector<int>> largest;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        largest.resize(n);
        for(int i = 0; i < n; i++) {
            largest[i].pb(i);
        }
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        vector<int> merge;
        vector<int> newmerge;
        for(auto &xx : largest[x]) merge.pb(xx);
        for(auto &yy : largest[y]) merge.pb(yy);
        sort(all(merge), greater<int>());
        merge.erase(unique(all(merge)), merge.end());
        for(int i = 0; i < min(sz(merge), 10); i++) {
            newmerge.pb(merge[i]);
        }
        largest[x] = newmerge;

        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    DSU uf(n+1);
    for (;q--;) { 
        int type; cin >> type;
        if (type == 1) {
            int u, v; cin >> u >> v;
            --u; --v;
            uf.merge(u, v);
        } else {
            int v, k; cin >> v >> k;
            --v; 
            int root = uf.find(v);
            if (uf.largest[root].size() < k) {
                cout << -1 << '\n';
            } else {
                cout << uf.largest[root][k - 1] + 1 << '\n';
            }
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

