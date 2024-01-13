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

const char nl = '\n';

void test_case() {
    ll y, x; cin >> y >> x;

    ll sq = max(y, x) - 1;
    ll ans = 1;
    if((y >= x && sq%2==0) || (x > y && sq%2==1)){
        ans = sq*sq + min(x, y);
    } else{
        ans = (sq+1)*(sq+1) - min(x, y) + 1;
    }

    cout << ans << nl;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

