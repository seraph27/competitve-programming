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
    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;
    int a3, b3; cin >> a3 >> b3;
    int a4, b4; cin >> a4 >> b4;
    int num = 0;

    if(a1 == a2){
        num = abs(b1-b2);
    } else if(a1 == a3){
        num = abs(b1-b3);
    } else{
        num = abs(b1-b4);
    }

    cout << num*num << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

