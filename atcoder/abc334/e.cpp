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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

using mint = modint998244353;

struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) {
        for(int i = 0; i < n; i++) p[i] = i;
    }

    int find(int v) {
        return p[v] == v ? v : p[v] = find(p[v]);
    }

    void merge(int u, int v) {
        u = find(u), v = find(v);
        if(u != v) {
            if(sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v];
            p[v] = u;
        }
    }

    bool same(int u, int v) {
        return find(u)==find(v);
    }
};

void shiina_mashiro() {
    int h, w; cin >> h >> w;
    vector<string> a(h);
    for(int i = 0; i < h; i++) cin >> a[i];

    DSU uf(h*w);
    mint red = 0;
    const pii dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(a[i][j] == '.') {
                red++;
                continue;
            }
            for(auto &[y, x] : dirs) {
                int nx = j + x, ny = i + y;
                if(ny<0 || ny>=h || nx<0 || nx>=w || a[ny][nx] == '.') continue;
                uf.merge(ny*w + nx, i*w + j);
            }
        }
    }

    set<int> has;
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) {
        auto get = uf.find(i*w+j);
        if(a[i][j] == '#') has.insert(get);
    }
    debug(has);
    int comp = has.size();

    mint sum = 0;
    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            set<int> has2;
            if(a[y][x] == '#') continue;
            for(auto&[dy, dx] : dirs) {
                int ny = y + dy, nx = x + dx;
                if(ny<0 || ny>=h || nx<0 || nx>=w || a[ny][nx] == '.') continue;
                has2.insert(uf.find(ny*w + nx));

            }
            sum += comp - has2.size() + 1;
        }
    }
    mint ans = sum * red.inv();
    cout << ans.val() << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}

