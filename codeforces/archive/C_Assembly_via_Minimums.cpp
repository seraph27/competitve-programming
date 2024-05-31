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
    int n; cin >> n;
    vector<int> v(n*(n-1)/2);

    for(auto &a : v){
        cin >> a;
    }

    sort(all(v));

    for(int i = 0; i < v.size(); i+=--n){
        cout << v[i] << " ";
    }

    cout << 1000000000 << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) test_case();
}