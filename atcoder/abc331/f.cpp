#include <bits/stdc++.h>
#include <atcoder/segtree>
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

constexpr int B = 5;
int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
int base[B];

struct Hash {
    ll h1, h2, pow;
};
using T = array<Hash, B>;

T op(T lhs, T rhs){
    T res;
    for(int i = 0; i < B; i++) {
        res[i].h1 = (lhs[i].h1 + lhs[i].pow * rhs[i].h1) % mod[i];
        res[i].h2 = (lhs[i].h2 * rhs[i].pow + rhs[i].h2) % mod[i];
        res[i].pow = lhs[i].pow * rhs[i].pow % mod[i];
    }
    return res;
}

T e() {
    T res;
    for(int i = 0; i < B; i++) res[i] = {0, 0, 1};
    return res;
}

T gen(char c) {
    T res;
    for(int j = 0; j < B; j++) {
        res[j].h1 = res[j].h2 = c, res[j].pow = base[j];
    }
    return res;
}

void shiina_mashiro() {
    int n, q; cin >> n >> q;
    string s; cin >> s;

    for (int i = 0; i < B; i++) base[i] = rng() % mod[i];
    
    vector<T> vi(n);
    for(int i = 0; i < n; i++) {
        vi[i] = gen(s[i]);
    }

    segtree<T, op, e> seg(vi);

    for(;q--;) {
        debug(q);
        int type; cin >> type;
        if(type == 1) {
            int x; char c;
            cin >> x >> c;
            --x;
            seg.set(x, gen(c));
        } else {
            int l, r; cin >> l >> r;
            --l;
            int ok = 1;
            auto h = seg.prod(l, r);
            for(int i = 0; i < B; i++) {
                debug(h[i].h1, h[i].h2);
                ok &= (h[i].h1 == h[i].h2);
            }
            cout << (ok ? "Yes" : "No") << nl;
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

