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
    vector<int> v(n);

    for(auto &a: v){
        cin >> a;
    }
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == i+1){
            count++;
        }
    }

    if(count %2 == 1){
        count++;
    }
    cout << count / 2 << "\n";

}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) test_case();
}