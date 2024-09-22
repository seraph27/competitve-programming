// Problem: B. Square or Not
// Contest: Codeforces Round 970 (Div. 3)
// URL: https://codeforces.com/contest/2008/problem/B
// Time Limit: 2000
// Start: 2024/09/01 22:41:43

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

bool isPerfectSquare(int num) {
    if (num < 0) return false;
    
    int root = sqrt(num);
    return root * root == num;
}

void shiina_mashiro() {
    int n; cin >> n;
    string s; cin >> s;
    if(!isPerfectSquare(n)) {
        cout<<"No"<<nl;
        return;
    }
    debug(sqrt(n), n);
    int side = (int)sqrt(n);
    int ok = 1;
    for(int i = 0; i < side; i++) {
        debug(i);
        if(s[i] == '0') {
            ok = 0;
            break;
        } 
    }
    for(int i = n-1; i>=n-side-1; i--) {
        debug(i);
        if(s[i] == '0') {
            ok = 0;
            break;
        }
    }
    debug(side);
    for(int i = side; i<n-side; i++) {
        if(i%side==0 || (i%side)==side-1) {
            debug(i);
            if(s[i] == '0') {
                ok = 0;
                break;
            }
        } else{
            if(s[i] == '1') {
                ok = 0;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
