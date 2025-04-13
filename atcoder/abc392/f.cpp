// Problem: $(PROBLEM)
// Contest: $(CONTEST)
// URL: $(URL)
// Time Limit: $(TIMELIM)
// Start: $(DATE)
// atcoder
#include <bits/stdc++.h>
#include <atcoder/modint>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
using namespace atcoder;
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

using mint = modint998244353;
const char nl = '\n';

struct fenwick{
    vector<int> bit;
    int size;
    fenwick(int n): size(n+1), bit(n+1) {}
    void add(int i, int x){
        for(++i; i < size; i += i & -i) bit[i] += x;
    }
    int sum(int i){
        int res = 0;
        for(++i; i; i -= i & -i) res += bit[i];
        return res;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
};
void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n), res(n);
    for(auto&a: vi) cin >> a;
    fenwick fw(n);
    for(int i = 0; i < n; i++) fw.add(i, 1);
    for(int i = n-1; ~i; --i){
        int l = 0, r = n-1, ans = l;
        while(l<=r) {
            int mid = (l+r)>>1;
            if(fw.sum(mid) >= vi[i]) r = mid-1, ans = mid;
            else l = mid+1;
        }
        fw.add(ans, -1);
        res[ans] = i+1;
    }
    for(auto &a : res) cout << a << " ";
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

