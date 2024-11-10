#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

// #indef MISAKA
// struct _debug {
// template<typename T> static void __print(const T &x) {
//     if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
//     else { cerr << '{'; int f{}; for(auto i : x) cerr << (f++?",":""), __print(i); cerr << '}';}
// }
// template<typenameT, typenameV>
// static void __print(const pair<T, V) &x) {cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ',';}
// template<typename T, typename...V> 
// static void _print(const T&t, const V&... v) {__print(t); if constexpr (sizeof...(v)) cerr << ",", _print(v...); else cerr << "]\n"; }}; 
// #define debug(x...) cerr << "[" << #x << "] = [", _debug::print(x)
// #else 
// #define debug(x...)
// #endif

void solve() {
    int n,m,q; cin >> n >> m >> q;
    vector<string> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    multiset<pair<string,int>> s;
    for(int i=0; i<n; i++) {
        s.insert({a[i],i});
    }
    //cerr << s.size() << "\n";
    for(int i=0; i<q; i++) {
        multiset<pair<string,int>> nxtvalid;
        int j; cin >> j;
        char c; cin >> c;
        for(auto it=s.begin(); it!=s.end(); it++) {
            if((*it).first[j-1]==c) {
                nxtvalid.insert(*it);
            }
        }
        s=nxtvalid;
    }
    //cerr << s.size() << "\n";
    if(s.size()>1) {
        cout << "ambiguous\n" << s.size();
    }
    else {
        cout << "unique\n" << (*s.begin()).second+1;
    }
}

signed main() {
    int t = 1;
    while(t--) {
        solve();
    }
}