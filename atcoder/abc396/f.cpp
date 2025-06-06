// Problem: F - Rotated Inversions
// Contest: AtCoder Beginner Contest 396
// URL: https://atcoder.jp/contests/abc396/tasks/abc396_f
// Time Limit: 2000
// Start: 2025/04/08 19:51:53
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


struct fenwick{
    int siz; vector<int> b;
    fenwick(int n) : siz(n), b(n+1){};

    void add(int p, int x) {
        p++;
        for(; p <= siz; b[p]+=x, p += p & -p);
    }

    int sum(int p) {
        int s = 0;
        for(;p; s+=b[p], p -= p & -p);
        return s;
    }

    int query(int l, int r) {
        return sum(r+1) - sum(l);
    }
};
void shiina_mashiro() {
    //53501 7
    //04012 3
    //15134 3
    //20245 1
    //
    //if its at a 5 then everything on its right we must minus, when reset to 0, we add everything on the left
    //maintain each element and how many rotations until it meet the next mod
    //then go through each of them 
    
    int n, m; cin >> n >> m;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;

    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[m-vi[i]-1].push_back(i);
    }

    int inv = 0;
    fenwick bit(m);
    for(int i = 0; i < n; i++) {
        inv += i - bit.query(0, vi[i]);
        bit.add(vi[i], 1);
    }
    cout << inv << nl;
    for(int i = 0; i < m-1; i++) {
        for(auto &x : mp[i]) {
            inv -= n-x-1;
            inv += x;
        }
        cout << inv << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

