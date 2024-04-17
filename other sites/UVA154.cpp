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

const int mod = 1e9+7;
const char nl = '\n';
const int INF = 1001001001;

void solve(vector<string> block) {
    map<char, map<char, int>> mp;
    for(int i = 0; i < block.size(); i++){
        for(int j = 0; j < 5; j++){
            int color = block[i][j*4];
            int trash = block[i][j*4+2];
            mp[color][trash]++;
        }
    }
    int ans = 0, mxdiff = INF;
    for(int i = 0; i < block.size(); i++){
        int diff = 0;
        for(int j = 0; j < 5; j++){
            int color = block[i][j*4];
            int trash = block[i][j*4+2];
            diff+=block.size()-mp[color][trash];
        }
        if(ckmin(mxdiff, diff)) ans = i+1;
    }
    cout << ans << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    string s;
    vector<string> block;
    while(getline(cin, s)){
        if(s=="#") break;
        else if(s[0]=='e'){
            solve(block);
            block.clear();
        } else{
            block.push_back(s);
        }
    }
}
