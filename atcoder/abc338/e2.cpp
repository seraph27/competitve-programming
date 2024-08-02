#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T query(int pos) {
        T s = 0;
        for (++pos; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return query(r) - query(l-1);
    }
    void update(int pos, T x) {
        for (++pos; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};

void seraph() {
    int n; cin >> n;
    fenwick<ll> fw(2*n);
    vector<pii> vi(n);
    for(int i = 0; i < n; i++) {
        cin>>vi[i].first >>vi[i].second;
    }
    for(int i = 0; i < n; i++) {
        auto &[a, b] = vi[i];
        --a;--b;
        if(a>b) swap(a, b);
        debug(fw.query(a), a, fw.query(b), b);

        if(fw.query(a)!=fw.query(b)) {
            cout<<"Yes"<<nl;
            return;
        }
        fw.update(a, 1);
        fw.update(b, -1);
    }
    cout<<"No"<<nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) seraph();
}

