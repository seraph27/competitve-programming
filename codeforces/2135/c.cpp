// Problem: C. By the Assignment
// Contest: Codeforces Round 1046 (Div. 1)
// URL: https://codeforces.com/contest/2135/problem/C
// Time Limit: 4000
// Start: Fri Aug 29 13:51:55 2025
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

vector<pii> bridges(int n, const vector<vector<pii>> &adj) {
    vector<int> tin(n, -1), low(n, 0), vis(n, 0);
    int timer = 0;
    vector<pii> res;

    auto dfs = [&](auto &&s, int u, int pe) -> void {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for (auto &[v, id] : adj[u]) {
            if (id == pe) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                s(s, v, id);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) res.pb({u, v});
            }
        }
    };

    for (int i = 0; i < n; i++) if (!vis[i]) dfs(dfs, i, -1);
    return res;
}

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

const int mod = 998244353;
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

void shiina_mashiro() {
    int n, m, v; cin >> n >> m >> v;
    vector<int> vi(n);
    for(auto&x : vi) cin >> x;

    vector<vector<int>> adj(n);
    vector<vector<pii>> adj2(n);
    int id = 0;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
        adj2[a].pb({b, id});
        adj2[b].pb({a, id});
        id++;
    }
    
    auto b = bridges(n, adj2);
    set<pii> s;
    for(auto&[c, d] : b) {
        s.insert({c, d});
        s.insert({d, c});
    }
    vector<int> color(n), vis(n), val;
    auto dfs = [&](auto&&ss, int u) -> bool {
        val.pb(vi[u]);
        vis[u] = 1;
        bool ok = true;
        for(auto&e : adj[u]) {
            if(s.count({u, e})) continue;
            if(!vis[e]) {
                color[e] = (color[u] == 1 ? 2 : 1);
                ok = ss(ss, e) && ok;
            } else {
                if(color[e] == color[u]) ok = false;
            }
        }
        return ok;
    };

    mint ans = 1;
    for(int u = 0; u < n; u++) if(!vis[u]) {
        val.clear();
        color[u] = 1;
        if(dfs(dfs, u)) {
            int has = 0, now = 0, bad = 0;
            for(auto&x : val) {
                if(x == -1) continue;
                if(!has) {now = x; has = 1;}
                else if(x != now) { bad = 1; break; }
            }
            if(bad) ans = 0;
            else {
                if(!has) ans*=mint(v);
            }
        } else {
            int bad = 0;
            for(auto&x : val) {
                if(x != 0 && x != -1) {
                    bad = 1;
                    break;
                }
            }
            if(bad) ans = 0;
        }
    }

    cout << ans.v << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

