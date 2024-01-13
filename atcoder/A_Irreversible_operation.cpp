#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;


    int64_t ans = 0;
    int currcnt = 0;

    for(auto& c : s){
        if (c == 'B') {
            currcnt++;
        } else {
            ans += currcnt;
        }
    }

    cout << ans << "\n";
}