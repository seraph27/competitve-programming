// Problem: E - 1D Bucket Tool
// Contest: AtCoder Beginner Contest 380
// URL: https://atcoder.jp/contests/abc380/tasks/abc380_e
// Time Limit: 2000
// Start: 2024/11/29 2:01:11
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

struct DSU {
    vector<int> par, siz, cnt, color, left;
    int sz;

    DSU(int n) {
        par.resize(n);
        color.resize(n);
        iota(all(color), 0);
        cnt.resize(n, 1);
        siz.resize(n, 1);
        left.resize(n);
        iota(all(left), 0);
        iota(all(par), 0);
        sz = n;
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }
    
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u==v) return;
        if(siz[u] < siz[v]) {
            swap(u, v);
        }
        siz[u] += siz[v];
        par[v] = u;
    }
    bool same(int u, int v) {
        return find(u) == find(v);
    }
};

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    DSU uf(n);

    for(;q--;) {
        int type; cin >> type;
        if(type==1) {
            int x, c; cin >> x >> c;
            --x; --c;
            int p = uf.find(x);
            int L = uf.left[p];
            int R = L + uf.siz[p];
            --L;
            uf.cnt[uf.color[p]]-=uf.siz[p];
            uf.color[p] = c;
            uf.cnt[c]+=uf.siz[p];
            if(L>=0 and uf.color[uf.find(L)] == uf.color[p]) {
                uf.left[p] = uf.left[uf.find(L)];
                uf.merge(L, x);
            }
            if(R<n and uf.color[uf.find(R)] == uf.color[p]) {
                uf.left[uf.find(R)] = uf.left[p];
                uf.merge(R, x);

            }
            debug(L, R);
        } else {
            int x; cin >> x;
            --x;
            cout << uf.cnt[x] << nl;
        }
        debug(uf.color, uf.cnt);
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

