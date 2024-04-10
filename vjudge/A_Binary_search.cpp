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
    int n, q; cin >> n >> q;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;

    for(int i = 0; i < q; i++){
        int query; cin >> query;
        auto ans = lower_bound(all(vi), query);
        int aa = *ans;
        cout << (aa!= query ? -1 : ans-vi.begin()) << nl;
    }
    

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}