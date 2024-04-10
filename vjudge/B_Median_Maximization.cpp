#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)

const int mod = 1e9+7;
const char nl = '\n';

void test_case() {
    int n, s; cin >> n >> s;

    int l = 0, r = (int)1e9+5, ans = -1;

    int median = (n%2 == 0) ? n/2 : n/2+1;

    while(l<=r){
        ll mid = (l+(r-l)/2);
        ll right = ((ll)n-median+1) * (ll)mid;
        ll tot = right;
            //cout << r << nl;
        if(tot <= s) {
            l = mid+1, ans = mid;
        } else r = mid-1;
    }
    cout << ans << nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}