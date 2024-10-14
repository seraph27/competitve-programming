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

bool op(pair<int,int>&a, pair<int, int>&b) {
    if(a.second==b.second) return a.first < b.first;
    return a.second > b.second;
}
void test() {
    int m; cin >> m;
    vector<pair<int, int>> vi(m);
    vector<string> sv(m);
    for(int i = 0; i < m; i++) {
        cin >> sv[i];
        vi[i].first = i;
        int p; cin >> p;
        int tot = p*10;
        vector<int> vii(6);
        for(int j = 0; j < 6; j++) {
            cin >> vii[j];
        }
        sort(all(vii));
        for(int j = 1; j <= 4; j++) {
            tot+=vii[j];
        }
        vi[i].second = tot;
    }
    sort(all(vi), op);
    multiset<int> s;
    for(int i = 0; i < m; i++) {
        if(vi[i].second < *s.begin() && s.size()>2) break;
        s.insert(vi[i].second);
        cout << sv[vi[i].first] << " " << vi[i].second << nl;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) test();
}


