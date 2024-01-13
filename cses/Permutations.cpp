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
    int n; cin >> n; 
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << nl;
        return;
    } 
    int i = 2;
    while(i <= n){
        cout << i << " ";
        i += 2;   
    }
    int j = 1;
    while(j <= n){
        cout << j << " ";
        j += 2;   
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

