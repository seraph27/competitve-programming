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
    vector<string> vi(10);
    for(int i = 0; i < 10; i++){
        cin >> vi[i];
    }
    vector<pair<int, int>> coord(3);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(vi[i][j] == 'B'){
                coord[0] = {i, j};
            }
            if(vi[i][j] == 'R'){
                coord[1] = {i, j};
            }
            if(vi[i][j] == 'L'){
                coord[2] = {i, j};
            }
        }
    }
    bool blocked = false;
    if(coord[0].first == coord[1].first && coord[1].first == coord[2].first || coord[0].second == coord[1].second && coord[1].second == coord[2].second) {
        if((coord[1].first - coord[0].first) * (coord[1].first - coord[2].first) < 0 || (coord[1].second - coord[0].second) * (coord[1].second - coord[2].second) < 0 ){
            blocked = true;
        }  
    }
   
    int ans = abs(coord[0].first - coord[2].first) + abs(coord[0].second - coord[2].second) - 1;
    if(blocked) ans += 2;
    cout << ans << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

