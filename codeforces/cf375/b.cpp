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
    string build = "";
    int flag = 0;
    vector<string> in, out;
    for(int i = 0; i < s.length(); i++) {
        if(s[i]=='_' || s[i]=='('||s[i]==')') {
            if(build != "") {
                if(flag) in.pb(build);
                else out.pb(build);
                build = "";
            }
            if(s[i]=='(') flag = 1;
            else if(s[i]==')') flag = 0;
            continue;
        }
        if(s[i] != '(' && s[i] != ')') build+=s[i];
    }
    if(build != "") {
        if(flag) in.pb(build);
        else out.pb(build);
    }
    debug(in);
    debug(out);
    int inans = 0;
    for(int i = 0; i < in.size(); i++) {
        inans++;
    }
    int outans = 0;
    for(int i = 0; i < out.size(); i++) {
        ckmax(outans, (int)out[i].size());
    }

    cout << outans << " " << inans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) seraph();
}

