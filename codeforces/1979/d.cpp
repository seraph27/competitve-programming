// Problem: D. Fixing a Binary String
// Contest: Codeforces Round 951 (Div. 2)
// URL: https://codeforces.com/contest/1979/problem/D
// Time Limit: 2000
// Start: 2024/09/14 0:22:19

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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 1;

    string new_s = "";
    int idx;
    auto oper = [&](int id) {
        string front = s.substr(0, id+1);
        string back = s.substr(id+1);
        reverse(all(front));
        idx = id + 1;
        new_s = back + front;
    };
    
    int ok = 1;
    for(int i = 0; i+1 < n; i++) {
        if(s[i] == s[i+1]) {
            cnt++;
        } else {
            if(cnt == k) {
                cnt = 1;
                continue;
            }
            ok = 0;
            if(cnt < k) {
                oper(i);
                break;
            } else {
                assert(i-k>=0);
                oper(i-k);
                break;
            }
            cnt = 1;
        }
    }
    
    if(ok) oper(n-1);
    for(int i = 0; i < k; i++) {
        if(new_s[i] != new_s[0]) {
            cout << -1 << nl;
            return;
        }
    }
    for(int i = 0; i+k < n; i++) {
        if(new_s[i] == new_s[i+k]) {
            cout << -1 << nl;
            return;
        }
    }
    if(ok) {
        cout << n << nl;
        return;
    }
    cout << idx << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
