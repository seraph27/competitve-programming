#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <int MOD_> struct modnum {
    static constexpr int MOD = MOD_;

    int v;

    modnum() : v(0) {}
    modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }

    explicit operator int() const { return v; }
    explicit operator bool() const { return v; }

    friend ostream& operator << (ostream& out, const modnum& n) { return out << n.v; }
    friend istream& operator >> (istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

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
        v = int((ll) v * o.v % MOD);
        return *this;
    }

    friend modnum binpow(modnum a, ll p) {
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

    friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
    friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
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


void test_case() {
	int n; cin >> n;
	vector<vector<int>> adj(n+1);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	vector<int> p(n+1), d(n+1), leaves;
	auto dfs = [&](auto&& s, int v) -> void {
		for (int u : adj[v]) if (u != p[v]) {
			d[u] = d[v] + 1;
			p[u] = v;
			s(s, u);
		}
	};
	dfs(dfs, 1);
	for (int i = 2; i <= n; i++) if (sz(adj[i]) == 1) leaves.emplace_back(i);
	vector<mint> dp(n+1);
	sort(all(leaves), [&](int x, int y) { return d[x] < d[y]; });
	vector<bool> vis(n+1);
	dp[1] = 1, vis[1] = 1;
	for (int v : leaves) {
		int tmp = v, len = 0;
		while (!vis[tmp]) tmp = p[tmp], len++;
		mint there = dp[tmp] * inv(mint(len));
		tmp = v;
		int dist = 0;
		while (!vis[tmp]) {
			vis[tmp] = 1, dp[tmp] = there * dist++, tmp = p[tmp];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " \n"[i==n];
	}


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

