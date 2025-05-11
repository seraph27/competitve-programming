// Problem: D. Needle in a Numstack
// Contest: Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/contest/2108/problem/D
// Time Limit: 3000
// Start: 2025/05/01 22:34:12
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

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    auto ask = [&](int x) -> int {
        debug(x+1);
        cout << "? " << x+1 << endl;
        int get; cin >> get;
        return get;
    };

    auto ans = [&](int a, int b, int ok) {
        if(!ok) cout << "! -1" << endl;
        else cout << "! " << a << " " << b << endl;
    };
    if(n>2 && k==1) {
        ans(0, 0, 0);
        return;
    }
    if(k+k==n) {
        ans(k, k, 1);
        return;
    }
    vector<int> vi(k), vi2(k), pos(k);
    for(int i = 0; i < k; i++) vi[i] = ask(i);
    for(int i = n-k; i < n; i++) {
        vi2[i%k] = ask(i);
        pos[i%k] = i;
    }
    debug(vi2);
    int ok = 0;
    int L = -1, R = -1;
    for(int i = 0; i < k; i++) if(vi[i] != vi2[i]) {
        ok = 1;
        int bL = i/k, bR = pos[i]/k;
        while(bR-bL > 1) {
            int mid = (bL+bR)>>1;
            auto now = ask(mid*k+i);
            if(vi[i] == now) {
                bL = mid;
            } else {
                bR = mid;
            }
        }
        L = bL*k+i;
        R = bR*k+i;
        break;
    }
    debug(L, R);
    if(!ok) {
        ans(0, 0, 0);
        return;
    }
    ckmax(L, k-1);
    ckmin(R, n-k);
    for(int i = L+1; i < R; i++) if(vi[i%k] != vi2[i%k]) {
        auto now = ask(i); 
        if(vi[i%k] == now) L = i;
        if(vi2[i%k] == now) R = i;
    }
    debug(R, L);
    if(R-L>1) {
        ans(0, 0, 0);
    } else {
        ans(R, n-R, 1);
    }

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

