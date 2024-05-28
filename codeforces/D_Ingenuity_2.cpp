#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void seraph() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    for(char c: s) mp[c]++;
    int tp = min(mp['S'], mp['N']), sd = min(mp['E'], mp['W']);
    mp['S']-=tp; mp['N']-=tp;
    mp['E']-=sd; mp['W']-=sd;
    int pair = tp+sd;
    int left = s.length()-pair*2;

    if(mp['N']%2 || mp['W']%2 || mp['E']%2 || mp['S']%2 || !left && pair < 2) {
        cout << "NO" << nl;
        return;
    }
    map<char, int> rmv;
    if(tp) {
        rmv['N']++; rmv['S']++;
    } else if(sd) {
        rmv['E']++; rmv['W']++;
    }
    rmv['E'] += mp['E'] / 2;
    rmv['S'] += mp['S'] / 2;
    rmv['W'] += mp['W'] / 2;
    rmv['N'] += mp['N'] / 2;
    for(char c: s){
        if(rmv[c]){
            cout << "R";
            rmv[c]--;
        } else cout << "H";
    }
    cout << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}