#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;

const char nl = '\n';
const int INF = 0x3f3f3f3f;

void test() {
    int n; cin >> n;
    map<int, int> mp;
    int x1, x2; cin >> x1 >> x2;
    int y1, y2; cin >> y1 >> y2;
    mp[x1]++;
    mp[x2]++;
    mp[y1]++;
    mp[y2]++;
    if(x1>10) x1=10;
    if(x2>10) x2=10;
    if(y1>10) y1=10;
    if(y2>10) y2=10;
    int john = x1+x2, mary=y1+y2;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++; 
        if(x>10)x=10;
        john+=x;
        mary+=x;
    }
    for(int i = 1; i <= 13; i++) {
        if(mp[i]==4) continue;
        int val = i<=10?i:10;
        if(john+val>23 && mary+val<=23) {
            cout << i;
            return;
        } 
        if(mary+val==23) {
            cout << i;
            return;
        }
    }
    cout << -1;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


