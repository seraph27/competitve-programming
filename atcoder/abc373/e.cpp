// Problem: E - How to Win the Election
// Contest: AtCoder Beginner Contest 373
// URL: https://atcoder.jp/contests/abc373/tasks/abc373_e
// Time Limit: 2500
// Start: Sun Oct  6 14:49:16 2024
// codeforces
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
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> vi(n);
    for(auto&a : vi) cin >> a;
    
    vector<ll> ans(n);
    vector<int> idxs(n);
    iota(all(idxs), 0);
    sort(all(idxs), [&](int a, int b){return vi[a] < vi[b];});
    sort(all(vi));
    vector<ll> pref(n+1);
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + vi[i];
    }
    ll sum = reduce(all(vi));
    auto ok = [&](ll addvote, ll now) -> bool {
        ll need = vi[now] + addvote + 1;
        auto dist = n - (lower_bound(all(pref), need) - pref.begin()) + 1;
        ll l = 1, r = dist-1, ans3 = l;
        while(l<=r) {
            ll mid2 = l + (r-l)/2;
            if(need * (r-mid2+1) - (pref[r] - pref[mid2-1] - (mid2 <= now ? vi[now] : 0) >= k-sum-addvote)) {
                r = mid2 - 1, ans3 = mid2;
            } else l = mid2 + 1;
        }
        ll cnt;
        if(ans3 <= now) cnt = ans3-1;
        else cnt = ans3;
        return cnt < m;
    }; //if i get mid votes, then i have a_i + mid votes. want to see if there can be M people more than a_i+mid+1 votes.
    for(int i = 0; i < n; i++) {
        ll l = 0, r = k-sum, ans2 = l;
        while(l<=r) {
            ll mid = l + (r-l)/2;
            if(ok(mid, i)) { //if there is such a X we want to find a better one
                r = mid - 1, ans2 = mid;
            } else {
                l = mid + 1;
            }
        }
        if(ok(ans2, i)) ans[idxs[i]] = ans2;
        else ans[idxs[i]] = -1;
    }
    for(auto &x : ans) cout << x << " ";
    cout << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    while (t--) shiina_mashiro();
}
