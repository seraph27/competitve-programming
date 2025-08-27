// Problem: P1763 埃及分数
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P1763
// Time Limit: 1000
// Start: Mon Aug 25 15:03:51 2025
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

int gcd(int x,int y){
	if(y==0)return x;
	else return gcd(y,x%y);
}
int deep = 1;
int now[11], ans[11];
bool ok = false;
void dfs(int a, int b, int d) {
    if(d > deep) return;
    if(a==1 && b > now[d - 1]) {
        now[d] = b;
        if(!ok || now[d] < ans[d]) memcpy(ans, now, sizeof(int) * (deep + 1));
        ok = 1;
        return;
    }
    if(d == deep - 1) {
        int K = iceil(4 * b, a * a);
        for(int k = K; ; k++) {
            int get = -1;
            int delta = a*a*k*k - 4*b*k;
            auto sq = isqrt(delta);
            if(sq*sq==delta) get = sq;
            else if((sq+1)*(sq+1)==delta) get = sq+1;
            else if((sq-1)*(sq-1)==delta) get = sq-1;
            int x = (a*k-get)/2;
            int y = (a*k+get)/2;
            if(y > 1e7 || (ok && y >= ans[deep])) break;
            if(get<=0 || (a*k-get) & 1) continue;
            now[deep-1] = x;
            now[deep] = y;
            memcpy(ans, now, sizeof(int) * (deep + 1));
            ok = 1;
            break;
        }
        return;
    }
    int L = max(iceil(b, a), now[d-1] + 1);
    int R = (deep - d + 1) * b / a;
    if(ok && R >= ans[deep]) R = ans[deep] - 1;
    for(int i = L; i < R; i++) {
        now[d] = i;
        int gd = gcd(a*i-b, b*i);
        dfs((a*i-b)/gd, b*i/gd, d + 1);
    }
}



void shiina_mashiro() {
    int a, b; cin >> a >> b;
    int gd = gcd(a, b);
    a/=gd, b/=gd;
    for(deep = 1; deep < 10; deep++) {
        ok = 0;
        dfs(a, b, 1);
        if(ok) {
            for(int i = 1; i <= deep; i++) cout << ans[i] << " ";
            cout << nl;
            return;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) shiina_mashiro();
}
