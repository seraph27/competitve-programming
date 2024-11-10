#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define fi first 
#define se second
using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for(auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ')';}
template<typename T, typename... V> 
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ",", _print(v...); else cerr << "]\n"; }}; 
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else 
#define debug(x...)
#endif

void solve() {
    int n,r; cin >> n >> r;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    sort(a.begin(),a.end());
    vector<int> ans;
    auto count = [&](int x) {
        return upper_bound(a.begin(),a.end(),x+r)-lower_bound(a.begin(),a.end(),x-r);
    };
    while(a.size()) {
        int mx=0;
        int bestDel=1e9;
        for(int i=0; i<a.size(); i++) {
            if(count(a[i]-r)>mx) {
                mx=count(a[i]-r);
                bestDel=a[i]-r;
            }
        }
        vector<int> nxt;
        for(int i=0; i<a.size(); i++) {
            if(abs(a[i]-bestDel)>r) {
                nxt.push_back(a[i]);
            }
        }
        a=nxt;
        ans.push_back(bestDel);
    }
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

signed main() {
    int t = 1;
    while(t--) {
        solve();
    }
}