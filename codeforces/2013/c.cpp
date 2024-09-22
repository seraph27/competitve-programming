// Problem: C. Password Cracking
// Contest: Codeforces Round 973 (Div. 2)
// URL: https://codeforces.com/contest/2013/problem/C
// Time Limit: 2000
// Start: 2024/09/20 23:35:49

#include <bits/stdc++.h>
#define sz(x) (int)x.size()
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
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;

    auto guess = [&](string s, int type, int isfront) -> int {
        if(isfront) {
            if(!type) s+='0';
            else s+='1';
        } else {
            if(!type) s = '0'+s;
            else s = '1'+s;
        }
        
        cout << "? " + s << endl;
        int get; cin >> get;
        return get;
    };

    string ans = "";

    int last = 0;
    while(sz(ans) < n) {
        if(guess(ans, 0, 1)) {
            ans+='0';
            continue;
        }
        if(guess(ans, 1, 1)) {
            ans+='1';
            continue;
        }
        break;
    }
    char bk = ans[0];
    debug(ans);
    int b = bk-'0';
    b^=1;
    debug(bk);

    while(sz(ans) < n) {
        if(guess(ans, b, 0)) {
            ans = to_string(b)+ans;
            continue;
        }
        if(guess(ans, b^1, 0)) {
            ans = to_string(b^1)+ans;
            continue;
        }
        break;
    }

    cout << "! " + ans << endl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
