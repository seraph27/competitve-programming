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

const ll sz = 1<<18;

ll n, arr[sz]; 
ar<ll, 4> tree[sz<<1]; //largest, cnt, 2nd larg, cnt

ar<ll, 4> comb(ar<ll, 4> a, ar<ll, 4> b) {
    map<ll, ll> mp;
    mp[a[0]]+=a[1];
    mp[a[2]]+=a[3];
    mp[b[0]]+=b[1];
    mp[b[2]]+=b[3];
    auto it = prev(mp.end());
    ar<ll, 4> res;
    res[0] = it->first;
    res[1] = it->second;
    --it;
    res[2] = it->first;
    res[3] = it->second;
    return res;
}

void build(ll tl, ll tr, ll p) {
    if(tl == tr) {tree[p] = {arr[tl], 1, 0, 0}; return;}
    ll m = (tl+tr)>>1;
    build(tl, m, p<<1), build(m+1, tr, (p<<1)|1);
    tree[p] = comb(tree[p<<1], tree[(p<<1)|1]);
}

void update(ll tl, ll tr, ll p, ll pos, ar<ll, 4> val) {
    if(tl == tr) {tree[p] = val; return;}
    ll m = (tl+tr)>>1;
    if(pos<=m) update(tl, m, p<<1, pos, val);
    else update(m+1, tr, (p<<1)|1, pos, val);
    tree[p] = comb(tree[p<<1], tree[(p<<1)|1]);
}

ar<ll, 4> getmx(ll l, ll r, ll tl, ll tr, ll p) {
    if(l<=tl && tr<=r) return tree[p];
    ll m = (tl+tr)>>1;
    ar<ll, 4> res = {0, 0, 0, 0};
    if(l<=m) res = comb(res, getmx(l, r, tl, m, p<<1));
    if(r>m) res = comb(res, getmx(l, r, m+1, tr, (p<<1)|1));
    return res;
}

void seraph() {
    int q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, n, 1);
    for(;q--;) {
        int type, a, b; cin >> type >> a >> b;
        if(type == 1) {
            update(1, n, 1, a, {b, 1, 0, 0});
        } else{
            cout << getmx(a, b, 1, n, 1)[3] << nl;
        }
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

