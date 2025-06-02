// Problem: G. Grouped Carriages
// Contest: COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1866/problem/G
// Time Limit: 3000
// Start: Fri May 30 23:45:51 2025
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
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
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n), door(n);
    for(int i = 0; i < n; i++) cin >> vi[i];
    for(int i = 0; i < n; i++) cin >> door[i];

    vector<ar<int, 3>> seg(n);
    for(int i = 0; i < n; i++) {
        seg[i] = {max(0LL, i - door[i]), min(n-1, i + door[i]), i};
    }
    int l = 0, r = *max_element(all(vi)), ans = 0;
    while(l<=r) {
        auto tmp = vi;
        auto segs = seg;
        sort(all(segs));
        int mid = (l+r) >> 1;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int curr = 0;
        bool ok = true;
        for(int i = 0; i < n; i++) {
            while(curr < n && segs[curr][0] <= i) {
                pq.push({segs[curr][1], segs[curr][2]});
                curr++;
            }

            int need1 = 0;
            while(!pq.empty() && pq.top().first == i) {
                auto [rb, idx] = pq.top(); pq.pop();
                need1 += tmp[idx];
                tmp[idx] = 0;
            }
            if(need1 > mid) {
                ok = false;
                break;
            }
            int need2 = mid - need1;
            while(need2 > 0 && !pq.empty()) {
                auto [rb, idx] = pq.top(); pq.pop();
                if(rb < i) {
                    ok = false;
                    break;
                }

                int take = min(need2, tmp[idx]);
                tmp[idx] -= take;
                need2 -= take;
                if(tmp[idx] > 0) {
                    pq.push({rb, idx});
                }
            }
            if(!ok) break;
        }
        if(ok) {
            r = mid - 1, ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

