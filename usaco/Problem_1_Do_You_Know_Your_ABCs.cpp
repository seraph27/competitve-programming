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
    int arr[7];
    int maxx = 0;
    for(int i = 0; i < 7; i++){
        cin >> arr[i];
        if(arr[i] > maxx) maxx = arr[i];
    }

    int small, big;
    for(int i = 0; i < 7; i++){
        for(int j = i+1; j < 7; j++){
            for(int k = j+1; k < 7; k++){
                if((arr[i] + arr[j] + arr[k]) == maxx){
                    small = min({arr[i], arr[j], arr[k]});
                    big = max({arr[i], arr[j], arr[k]});

                }
            }
        }
    }
    cout << small << " " << maxx - small - big << " " << big << nl;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

