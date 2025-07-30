// Problem: Problem 2. Rental Service
// Contest: USACO 2018 January Contest, Silver
// URL: https://usaco.org/index.php?page=viewproblem2&cpid=787
// Time Limit: 4000
// Start: Mon Jul 28 23:31:09 2025
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

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    int r; cin >> r;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    
    vector<pii> store(m);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        store[i] = {y, x};
    }

    vector<int> rent(r);
    for(int i = 0; i < r; i++) cin >> rent[i];
    sort(all(vi), greater<int>());
    sort(all(store), greater<pii>());
    sort(rent.rbegin(), rent.rend());

    vector<int> sell(n+2, 0);
    
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        int milk = vi[i-1];
        while(idx < m) {
            auto [price, cnt] = store[idx];
            if(milk >= cnt) {
                sell[i] += cnt * price;
                milk -= cnt;
                idx++;
            } else {
                sell[i] += milk * price;
                store[idx].second-=milk;
                break;
            }
        }
        sell[i+1]+=sell[i];
    }

    vector<int> rpt(r+1, 0); //rent profit
    for(int i = 1; i <= r; i++) {
        rpt[i] = rpt[i-1] + rent[i-1];
    }

    int best = 0;
    for(int i = 0; i <= min(n, r); i++) {
        int left = n - i;
        auto tot = rpt[i] + sell[left];
        ckmax(best, tot);
    }
    cout << best << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("rental.in","r",stdin); freopen("rental.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

