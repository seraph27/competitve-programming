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
    int n, k; cin >> n >> k;
    vector<ll> vi(n), b(n);
    for(auto&a: vi) cin >> a;
    for(auto&x: b) cin >> x;

    int flag = 0;
    int k2 = k;
    vector<ll> ones;
    ll mx = 0;
    for(int i = 0; i < n; i++) {
        if(b[i]) {
            ones.pb(vi[i]);
            flag = 1;
            ckmax(mx, vi[i]);
        }
    }
    sort(all(ones));
    debug(ones);
    vector<ll> pref;
    if(ones.size()>1) for(ll i = 0, cnt = 1; i+1 < ones.size(); i++) {
        pref.pb((ones[i+1] - ones[i]) * cnt);
        cnt++;
    }
    
    ll ans1 = 0;
    vector<ll> temp = vi;
    temp.erase(find(all(temp), mx));
    assert(((temp.size()+1)/2+1) > 0);
    ans1 = mx + (flag ? k : 0) + temp[(temp.size()+1)/2-1];

    ll ans3 = 0;
    mx = *max_element(all(vi));
    temp = vi;
    temp.erase(find(all(temp), mx));
    assert(((temp.size()+1)/2+1) > 0);
    ans3 = mx + (flag ? k : 0) + temp[(temp.size()+1)/2-1];
    
    ll ans2 = 0;
    ll now = 0;
    debug(pref);
    while(pref.size() && k-pref[now]>=0 && now < pref.size()) {
        k-=pref[now];
        now++;
    }
    int left = k % (now + 1);
    if(k) {
        ans2 = ones[now] + k / (now+1);
    }
    for(int i = 0, cnt = 0; i < n && cnt < now+1; i++, cnt++) {
        if(now < ones.size() && b[i] && vi[i] <= ones[now]) {
            vi[i] = ans2;
            if(left>0) vi[i]++;
            left--;
        }
    }
    debug(now, k, ans2, vi);

    debug(ans1, ans2, ans3);
    cout << max({ans1, ans2, ans3}) << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

