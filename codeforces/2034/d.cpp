// Problem: D. Darius' Wisdom
// Contest: Rayan Programming Contest 2024 - Selection (Codeforces Round 989, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/2034/problem/D
// Time Limit: 2000
// Start: 2024/11/30 7:07:06
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<int>vi(n);
    for(auto &x:vi) cin >> x;

    int z = 0, o = 0, t = 0;
    set<int> idxz, idxo, idxt;
    for(int i = 0; i < n; i++) {
        if(vi[i] == 0) z++, idxz.insert(i);
        else if(vi[i] == 1) o++, idxo.insert(i);
        else t++, idxt.insert(i);
    }
    
    int moves = 0;
    vector<ar<int, 2>> ans;
    for(int i = 0; i < n && moves <= n; i++) {
        if(!idxz.empty() && !idxo.empty() && *prev(idxz.end()) > *idxo.begin()) { 
            auto val1 = *idxo.begin();
            auto val2 = *prev(idxz.end());
            swap(vi[val1], vi[val2]);
            ans.pb({val1, val2});
            moves++;
            idxz.erase(prev(idxz.end()));
            idxo.erase(idxo.begin());
            idxz.insert(val1);
            idxo.insert(val2);
        }
        if(!idxt.empty() && !idxo.empty() && *idxt.begin() < *prev(idxo.end())) {
            auto val1 = *prev(idxo.end());
            auto val2 = *idxt.begin();
            swap(vi[val1], vi[val2]);
            ans.pb({val1, val2});
            moves++;
            idxt.erase(idxt.begin());
            idxo.erase(prev(idxo.end()));
            idxt.insert(val1);
            idxo.insert(val2);
        }
    }
    debug(idxz, idxo, idxt);
    debug(ans);
    debug(vi);
    cout << moves << nl;
    for(auto [x, y]:ans) cout << x+1 << ' ' << y+1 << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

