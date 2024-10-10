#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
void test_case() {
    int n, m; ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &x : a) cin >> x, sum += x;
    vector<ll> b(a);
    sort(all(a));
    vector<ll> pref(a);
    for (int i = 1; i < n; i++) pref[i] += pref[i-1];
    auto above = [&](ll x, ll orig) {
        int pos = upper_bound(all(a), x) - a.begin();
        int l = 0, r = pos-1, e = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            int have = pos - mid - (a[mid] <= orig);
            ll got = pref[pos-1] - (mid ? pref[mid-1] : 0) - (a[mid] <= orig ? orig : 0);
            if (have * (x + 1) - got <= k - sum - (x - orig)) e = have, r = mid-1;
            else l = mid+1;
        }
        return n - pos + e;
    };
    for (int i = 0; i < n; i++) {
        auto ok = [&](ll u) {
            return above(b[i] + u, b[i]) < m;
        };
        ll l = 0, r = k - sum, ans = -1;
        while (l <= r) {
            ll mid = (l+r)/2;
            if (ok(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        cout << ans << " "; 
    }
    cout << '\n';

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}
