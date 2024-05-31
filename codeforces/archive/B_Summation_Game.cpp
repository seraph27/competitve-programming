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
    int n, k, x; cin >> n >> k >> x;
    vector<int> vi(n);
    for(int i = 0; i < n; i++){
        cin >> vi[i];
    }

    sort(all(vi));
    int sum = accumulate(all(vi), 0);

    int dp[n+5];
    int init = accumulate(vi.begin() + (n - x), vi.end(), 0);
    dp[0] = sum - init * 2;
    int ans = dp[0];
    for(int i = 0; i < k; i++){
        int diff;
        if(n-i-x-1 >= 0){
            diff = vi[vi.size() - 1 - i] - vi[vi.size()-1-i-x] * 2;
        } else{
            diff = vi[vi.size() - 1 - i];
        }

        dp[i+1] = dp[i]+diff;
        if(dp[i+1] > ans) ans = dp[i+1];
    
    }

    cout << ans << nl;

}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

