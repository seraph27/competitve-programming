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

    int lower = 0, upper = INT_MAX;
    vector<int> remove; 
    for(int i = 0; i < n; i++){
        int a, x; cin >> a >> x;
        if(a == 1){
            if(x > lower) lower = x;
        } else if(a == 2){
            if(x < upper) upper = x;
        } else{
            remove.push_back(x);
        }
    }

    int cnt = 0;
    for(int i = 0; i < remove.size(); i++){
        if(remove[i] >= lower && remove[i] <= upper){
            cnt++;
        }
    }
    if(upper - lower >= 0){
        cout << upper - lower + 1 - cnt << nl;
    } else{
        cout << 0 << nl;
    }
    
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

