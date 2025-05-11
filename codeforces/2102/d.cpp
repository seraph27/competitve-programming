 Problem: D. Quartet Swapping
// Contest: Codeforces Round 1024 (Div. 2)
// URL: https://codeforces.com/contest/2102/problem/D
// Time Limit: 2000
// Start: Sun May 11 09:24:05 2025
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
    int n; cin >> n;
    vector<int> vi(n);
    for(auto &i : vi) cin >> i;
    vector<int> v1, v2;
    for(int i = 0; i < n; i++) {
        if(i%2==0) v1.pb(vi[i]);
        else v2.pb(vi[i]);
    }

    auto par = [&](vector<int>&v) -> int {
        int nn = sz(v);
        vector<pair<int,int>> tmp(nn);
        for (int i = 0; i < nn; i++) tmp[i] = {v[i], i};
        sort(all(tmp));
        vector<int> idx(nn);
        for(int j = 0; j < nn; j++) {
            idx[tmp[j].second] = j;
        }
        vector<int> vis(nn);
        int p = nn%2;
        for(int i = 0; i < nn; i++) {
            if(vis[i]) continue;
            vis[i] = 1;
            p^=1;
            for(int j = idx[i]; j!=i; j = idx[j]) {
                vis[j] = 1;
                debug(vis, j, i, v);
            }
        }
        return p;
    };

    auto p1 = par(v1);
    auto p2 = par(v2);
    vector<int> ans(n);
    sort(all(v1));
    sort(all(v2));
    for(int i = 0; i < sz(v1); i++) {
        ans[i*2] = v1[i];
    }
    for(int i = 0; i < sz(v2); i++) {
        ans[i*2+1] = v2[i];
    }
    if(p1 ^ p2) swap(ans[n-1], ans[n-3]);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

