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

vector<int> countfreq(string s){
    vector<int> freq(26);
    for(int i = 0; i < s.length(); i++){
        freq[s[i]-'a']++;
    }
    return freq;
}

void test_case() {
    int n; cin >> n;
    vector<pair<string, string>> vi(n);

    for(int i = 0; i < n; i++){
        string sa, sb; cin >> sa >> sb;
        vi[i] = {sa, sb};
    }

    vector<int> ans(26);
    for(int i = 0; i < n; i++){
        vector<int> v1 = countfreq(vi[i].first);
        vector<int> v2 = countfreq(vi[i].second);
        for(int j = 0; j < 26; j++){
            ans[j] += max(v1[j], v2[j]);
        }
    }

    for(auto &a: ans) cout << a << nl;
}
int main() {    
    cin.tie(0)->sync_with_stdio(0);
    // freopen("blocks.in", "r", stdin);
    // freopen("blocks.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}

