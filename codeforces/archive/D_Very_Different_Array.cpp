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
    int n1, n2; cin >> n1 >> n2; 
    vector<int> v1(n1);
    vector<int> v2(n2);
    for(auto &a : v1){
        cin >> a;
    }
    for(auto &a : v2){
        cin >> a;
    }

    sort(all(v1));
    sort(all(v2));

    ll D = 0;
    
    while(v1.size() > 0){
        ll diff1 = abs(v1[v1.size()-1] - v2[0]);
        ll diff2 = abs(v1[0] - v2[v2.size() - 1]);
        ll diff3 = abs(v1[0] - v2[0]);
        ll diff4 = abs(v1[v1.size()-1] - v2[v2.size()-1]);
        ll maxdiff = max({diff1, diff2, diff3, diff4});
        D += maxdiff;
        if(maxdiff == diff1){
            v1.pop_back();
            v2.erase(v2.begin());
        }else if(maxdiff == diff2){
            v1.erase(v1.begin());
            v2.pop_back();
        } else if(maxdiff == diff3){
            v1.erase(v1.begin());
            v2.erase(v2.begin());
        } else{
            v1.pop_back();
            v2.pop_back();
        }
    }

    cout << D << nl;


}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}

