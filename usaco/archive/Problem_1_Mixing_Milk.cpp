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
    ar<int, 3> cap = {};
    ar<int, 3> init = {};
    for(int i = 0; i < 3; i++){
        int a1, a2; cin >> a1 >> a2;
        cap[i] = a1;
        init[i] = a2;
    }

    for(int i = 0; i < 100; i++){
        int idx = i%3;
        int nextidx = (i+1)%3;
        int nextpour = cap[nextidx] - init[nextidx];
        int amt = nextpour >= init[idx] ? init[idx] : nextpour;
        init[idx] -= amt;
        init[nextidx] += amt;
    }

    for(int i = 0; i < 3; i++){
        cout << init[i] << nl;
    }

    
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

