// test case generator for stress testing
// run as: ./gen <seed>  -> prints one test case to stdout
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back

using namespace std;

mt19937_64 rng(0);
ll rint(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

int main(int argc, char **argv) {
    ll seed = argc > 1 ? atoll(argv[1]) : (ll)chrono::steady_clock::now().time_since_epoch().count();
    rng.seed(seed);

    // EDIT BELOW: print one test case to stdout
    ll n = rint(1, 10);
    cout << n << "\n";
    for (ll i = 0; i < n; i++) cout << rint(1, 20) << " \n"[i == n - 1];
}
