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
    int n; cin >> n;
    set<pair<int, int>> womp;
    while(sz(womp) < 4) {
        n = n + n/13 + 15;
        debug(n);
        int b = n%10;
        int b2 = n/10%10;
        womp.insert({b2, b});
    }
    debug(womp);
    int wum = 0, cnt = 0;
    int lasttp = -1, lastbt = 0;
    while(wum < 4) {
        string s; cin >> s;
        int tp = s[0]-'0', bt = s[1]-'0';
        if(lasttp!=-1) {
            cnt++;
            cout << abs(tp-lasttp) + abs(bt-lastbt) << nl;
        }
        if(womp.count({tp, bt})) {
            cout << "You hit a wumpus!" << nl;
            womp.erase({tp, bt});
            wum++;
        }
        lasttp = tp, lastbt = bt;
    }
    cout << "Your score is " << cnt+1 << " moves." << nl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
