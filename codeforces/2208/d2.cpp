#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>


#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
using vc = vector<int>;
using vvc = vector<vc>;
using vvvc = vector<vvc>;
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

const int MX = 8000;

struct DSU {
    int f[MX], siz[MX];
    
    DSU() {}
    
    void init(int n) {
        iota(f, f + n, 0);
        fill(siz, siz + n, 1);
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
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
} uf;

bitset<MX> bs[MX];
int cnt[MX];
int ord[MX];
string s;
pii res[MX];
int idx;

void shiina_mashiro() {
    int n; cin >> n;
    bool ok = true;

    idx = 0;

    for(int i = 0; i < n; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        bs[i] = bitset<MX>(s);
        cnt[i] = bs[i].count();
        if(!bs[i].test(i)) ok = false;
    }

    iota(ord, ord + n, 0);
    sort(ord, ord + n, [&](const int &i, const int &j) { return cnt[i] < cnt[j]; });
    uf.init(n);
    for(int i = 0; ok and i < n; i++) {

        int u = ord[i];
        auto curr = bs[u];
        auto reach = cnt[u];
        for(int j = i - 1; ~j; j--) {
            int v = ord[j];
            if(cnt[v] >= reach) continue;
            if(!curr[v]) continue;
            if((bs[v] & curr) == bs[v]) {
                res[idx++] = {u, v};
                uf.merge(u, v);
                curr ^= bs[v];
                reach -= cnt[v];
            }
        }
        if(reach != 1 || !curr.test(u)) ok = false;
    }

    if(!ok || uf.size(0) != n || idx != n - 1) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        for(int i = 0; i < idx; i++) cout << res[i].first + 1 << " " << res[i].second + 1 << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
