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
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &a: v){
        cin >> a;
    }

    if(v[0] == v[n-1]){
        if(count(v.begin(), v.end(), v[0]) >= k){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
        
    } else{
        int left = 0, right = 0;
        int i = 0, j = n-1;
        int leftidx = 0, rightidx = 0;

        for(; i < n; i++){
            if(v[i] == v[0]){
                left++;
                leftidx = i;
            }
            if(left == k){
                break;
            }

        }
        for(; j >= 0; j--){
            if(v[j] == v[n-1]){
                right++;
                rightidx = j;
            }
            if(right == k){
                break;
            }
        }

        if(i>=j || right < k || left < k){
            cout << "no" << "\n";
        } else{
            cout << "yes" << "\n";
        }
        
        
        
    }


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) test_case();
}