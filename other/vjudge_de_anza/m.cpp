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
    int n, m; cin >> n >> m;
    vector<int> def, atk;
    for(int i = 0; i < n; i++) {
        string type; cin >> type;
        int x; cin >> x;
        if(type == "DEF") def.pb(x);
        else atk.pb(x);
    }
    vector<int> cards(m);
    for(auto&a: cards) cin >> a;
    sort(all(cards));
    auto cardscopy = cards;
    sort(all(def));
    sort(all(atk));
    int mx1 = 0, mx2 = 0; //break defense and ignore def and only hitting atk

    int hasdef = 0;
    for(int i = 0; i < def.size(); i++) {
        auto it = upper_bound(all(cards), def[i]);
        if(it == cards.end()) {
            hasdef = 1;
            mx1 = 0;
            break;
        } 
        cards.erase(it);
    }
    debug(mx1);
    int cleared = 1;
    for(int i = 0; i < atk.size(); i++) {
        auto it = lower_bound(all(cards), atk[i]);
        if(it == cards.end()) {
            cleared = 0;
            break;
        }
        mx1 += *it - atk[i];
        cards.erase(it);
    }
    debug(mx1);
    if(!hasdef && cleared) {
        for(int i = 0; i < cards.size(); i++) mx1+=cards[i];
    }

    for(int i = 0; i < atk.size(); i++) {
        if(cardscopy.size()) {
            auto b = cardscopy.back(); cardscopy.pop_back();
            if(b-atk[i]>0) mx2+= b - atk[i];
        } else{
            break;
        }
    }
    debug(mx1, mx2);
    cout << max(mx1, mx2) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;

    while (t--) seraph();
}

