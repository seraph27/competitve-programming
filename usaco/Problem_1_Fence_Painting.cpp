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
    int a, b, c, d; cin >> a >> b >> c >> d;
    int overlap = 0; 
    if(max(a, b) < min(c, d)){
        overlap = min(c, d) - max(a, b);
    }else if (max(c, d) < min(a, b)){
        overlap = min(a, b) - max(c, d);
    }

    cout << max(a, max(b, max(c, d))) - min(a, min(b, min(c, d))) - overlap;
}

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}