// Problem: F - Connecting Points
// Contest: AtCoder Beginner Contest 409
// URL: https://atcoder.jp/contests/abc409/tasks/abc409_f
// Time Limit: 2000
// Start: Sat Aug 16 16:14:46 2025
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

struct DSU {
    vector<int> f, siz;
    vector<vector<int>> buc;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        buc.resize(n);
        for(int i = 0; i < n; i++) buc[i].pb(i);
    }

    void add() {
        auto SZ = sz(f);
        f.pb(SZ);
        siz.pb(1);
        buc.pb(vector<int>{SZ});
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
        if(sz(buc[x]) < sz(buc[y])) swap(buc[x], buc[y]);
        for(auto &e : buc[y]) buc[x].pb(e);
        buc[y].clear();
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    vector<pii> pts(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
    }
    DSU uf(n);
    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;

    auto f = [&](int i, int j) -> int {
        return abs(pts[i].first - pts[j].first) + abs(pts[i].second - pts[j].second);
    };
    for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++) {
        pq.push({f(i, j), i, j});  
    }
    int id = n-1;
    for(int i = 0; i < q; i++) {
        int type; cin >> type;
        if(type == 1) {
            int a, b; cin >> a >> b;
            id++;
            pts.pb({a, b});
            uf.add();
            for(int j = 0; j < sz(uf.buc); j++) if(sz(uf.buc[j])) {
                int mn = 4e18, idx = -1;
                for(auto &e : uf.buc[j]) {
                    if(ckmin(mn, f(e, id))) idx = e;
                }
                pq.push({f(idx, id), idx, id});
                
            }
        } else if(type == 2) {
            if(uf.size(0) == id + 1) {
                cout << -1 << nl;
                continue;
            }
            while(!pq.empty()) {
                auto [dist, comp1, comp2] = pq.top(); pq.pop();
                if(uf.same(comp1, comp2)) continue;
                uf.merge(comp1, comp2);
                while(!pq.empty() && pq.top()[0] == dist) {
                    auto [a, b, c] = pq.top(); pq.pop();
                    uf.merge(b, c);
                }
                cout << dist << nl;
                break;
            }
            
        } else {
            int u, v; cin >> u >> v;
            --u; --v;
            cout << (uf.same(u, v) ? "Yes" : "No") << nl;
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

