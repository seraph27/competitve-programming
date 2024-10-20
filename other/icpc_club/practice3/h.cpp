#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', 
        __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ",
        _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif
const char nl = '\n';

void solve(){
    int n, m, s, p, q; cin >> n >> m >> s >> p >> q;
    int ans = 0;
    map<int, set<pair<int, int>>> mp; //map page to items on that page
    int mnpage = 1e9, mxpage = 0; 
    for(int i = 0; i < p; i++) {
        int x; cin >> x;
        int xpage = (x+m-1)/m;
        mnpage = min(mnpage, xpage);
        mxpage = max(mxpage, xpage);
        mp[xpage].insert({x, 0});
    }

    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        int xpage = (x+m-1)/m;
        mnpage = min(mnpage, xpage);
        mxpage = max(mxpage, xpage);
        if(mp[xpage].count({x, 0})) mp[xpage].erase({x, 0});
        else mp[xpage].insert({x, 1});
    }
    if(mp.empty()) {
        cout << 0 << nl;
        return;
    }
    int movepage = abs(mnpage-mxpage) + min(abs(s-mnpage), abs(s-mxpage));
    int xx = 0;
    for(auto [k, v] : mp) {
        int need = 0, dontneed = 0;
        for(auto &x : v) {
            if(x.second) need++;
            else dontneed++;
        }
        if(!sz(v)) continue;
        int selectall = 1 + (m-need), deselectall = 1 + need;
        int mn = min({need+dontneed, selectall, deselectall});
        xx+=mn;
    }
    cout << movepage + xx << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
