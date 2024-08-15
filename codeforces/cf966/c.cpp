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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 0x3f3f3f3f;

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    
    int q; cin >> q;
    vector<int> ans;
    for(;q--;) {
        int bad = 0;
        string s; cin >> s;
        map<int , char> mp;
        map<char, int> mp2;
        for(int i = 0; i < s.length(); i++) {
            if(s.length() != vi.size()) {
                bad = 1;
                break;
            }
            if(!mp.count(vi[i])) mp[vi[i]] = s[i];
            else {
                if(mp[vi[i]] != s[i]) {
                    bad = 1;
                    break;
                }
            }

            if(!mp2.count(s[i])) mp2[s[i]] = vi[i];
            else {
                if(mp2[s[i]] != vi[i]) {
                    bad = 1;
                    break;
                }
            }

        }
        ans.pb((bad ? 1 : 0));

    }
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i]) cout << "No" << nl;
        else cout << "Yes" << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

