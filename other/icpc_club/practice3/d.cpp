#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
template<typename T> bool ckmax(T &a, const T&b) { return a < b ? a = b, 1 : 0;}
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
bool op(pair<int, char> &a, pair<int, char>&b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
void solve(){
    int n, m; cin >> n >> m;
    vector<string> vi(n);
    for(int i = 0; i < n; i++) cin >> vi[i];

    string ans = "";
    
    for(int j = 0; j < m; j++){

        map<char, int> mp;
        for(int i = 0; i < n; i++) {
            char c = vi[i][j];
            mp[c]++;
        }
        int now = 0;
        char add;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(ckmax(now, it->second)) add = it->first;
        }
        ans+=add;

    }
    cout << ans << nl;

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
