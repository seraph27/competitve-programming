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

ll findW(int n, ll sumsq, ll c) {
    ll low = 1, high = 1e9 + 7;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        ll check = mid * (mid * n + sumsq);
        if (check >= c) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

void test_case() {
    int n; cin >> n;
    ll c; cin >> c;
    
    ll sumsq = 0;
    for(int i = 0; i < n; i++){
        int s; cin >> s;
        sumsq += s;
        c-= s*s;
    }

    c/= 4;


    ll ans = findW(n, sumsq, c);

    cout << ans << endl;
   
    
}



int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}