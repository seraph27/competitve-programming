// Problem: E. Cactus
// Contest: Codeforces Round 143 (Div. 2)
// URL: https://codeforces.com/contest/231/problem/E
// Time Limit: 2000
// Start: Fri Aug 22 15:25:19 2025
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

template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;

    int v;

    modnum() : v(0) {}
    modnum(int v_) : v(v_ % MOD) { if (v < 0) v += MOD; }

    explicit operator int() const { return v; }
    explicit operator bool() const { return v; }

    friend ostream& operator << (ostream& out, const modnum& n) { return out << n.v; }
    friend istream& operator >> (istream& in, modnum& n) { int v_; in >> v_; n = modnum(v_); return in; }

    friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum operator- () const {
        return neg();
    }
    modnum operator+ () const {
        return modnum(*this);
    }

    modnum& operator ++ () {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator -- () {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }
    modnum& operator += (const modnum& o) {
        v -= MOD-o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator -= (const modnum& o) {
        v -= o.v;
        v = (v < 0) ? v + MOD : v;
        return *this;
    }
    modnum& operator *= (const modnum& o) {
        v = v * o.v % MOD;
        return *this;
    }

    friend modnum binpow(modnum a, int p) {
        if (p == 0) return 1;
        modnum ret = 1;
        for (; p; p /= 2, a *= a) if (p&1) ret *= a;
        return ret;
    }

    modnum inv() const {
        return binpow(*this, MOD-2);
    }
    friend modnum inv(const modnum& m) { return m.inv(); }

    modnum& operator /= (const modnum& o) {
        return *this *= o.inv();
    }

    modnum neg() const {
        modnum res;
        res.v = v ? MOD-v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

    friend modnum operator ++ (modnum& a, int32_t) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int32_t) { modnum r = a; --a; return r; }
    friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

const int mod = 1e9+7;
using mint = modnum<mod>;

vector<mint> facs, invfacs;

mint choose(int _a, int _b) {
    if (_b > _a || _a < 0 || _b < 0) return 0;
    return facs[_a] * invfacs[_b] * invfacs[_a-_b];
}

void finit(const int nx) {
    facs.resize(nx+1);
    invfacs.resize(nx+1);
    facs[0] = facs[1] = invfacs[0] = invfacs[1] = 1;
    for (int i = 2; i <= nx; i++) {
        facs[i] = facs[i-1] * mint(i);
    }
    invfacs[nx] = inv(facs[nx]);
    for (int i = nx-1; i > 1; i--) {
        invfacs[i] = invfacs[i+1] * mint(i+1);
    }
}

const char nl = '\n';

void shiina_mashiro() {
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vector<int> cycle_id(n, -1), backedge_id(n, -1);
    int idx = n;
    vector<int> dep(n, 0), par(n, -1), dp(n);

    auto dfs = [&](auto&&s, int u) -> void {
        dp[u] = 0;
        for(auto&e : adj[u]) {
            if(!dep[e]) {
                par[e] = u;
                dep[e] = dep[u] + 1; 
                s(s, e);
                dp[u] += dp[e];
            } else if(dep[e] < dep[u]) {
                if(e != par[u] && backedge_id[u] == -1) backedge_id[u] = idx++;
                dp[u]++;
            } else if(dep[e] > dep[u]) {
                dp[u]--;
            }
        }
        if(par[u] != -1) dp[u]--;

        if(backedge_id[u] != -1) cycle_id[u] = backedge_id[u];
        else {
            cycle_id[u] = u;
            for(auto &e : adj[u]) if(par[e] == u) {
                if(cycle_id[e] != e && dp[e] > 0) cycle_id[u] = cycle_id[e];
            }
        }
    };
    par[0] = -1, dep[0] = 1;
    dfs(dfs, 0);

    vector<vector<int>> adj2(idx);
    for(int u = 0; u < n; u++) {
        for(auto &e : adj[u]) if(e < u) {
            int x = cycle_id[u], y = cycle_id[e];
            if(x != y) adj2[x].pb(y), adj2[y].pb(x);
        }
    }
    const int LOG = 20;
    vector<vector<int>> up(idx, vector<int>(LOG));
    vector<int> depth(idx, -1), pref(idx, 0);

    auto dfs2 = [&](auto&&s, int u, int p) -> void {
        up[u][0] = (p==-1 ? u : p);
        for(int j = 1; j < LOG; j++) up[u][j] = up[up[u][j-1]][j-1];
        for(auto&e : adj2[u]) if(e != p) {
            depth[e] = depth[u] + 1;
            pref[e] = pref[u] + (e >= n); 
            s(s, e, u);
        }
    };
    
    int root = cycle_id[0];
    depth[root] = 0;
    pref[root] = root >= n; 
    dfs2(dfs2, root, -1);

    auto lca = [&](int a, int b) -> int {
        if(depth[a] < depth[b]) swap(a, b);
        int d = depth[a] - depth[b];
        for(int j = 0; j < LOG; j++) if(d >> j & 1) a = up[a][j];
        if(a == b) return a;
        for(int j = LOG - 1; j >= 0; j--) {
            if(up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    };
    int k; cin >> k;
    while(k--) {
        int a, b; cin >> a >> b;
        --a; --b;
        a = cycle_id[a], b = cycle_id[b];
        auto c = lca(a, b);
        int f = pref[a] + pref[b] - 2 * pref[c] + (c >= n);
        mint ans = binpow(mint(2), f);
        cout << ans.v << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

