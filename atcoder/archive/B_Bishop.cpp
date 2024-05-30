#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 
#include <typeinfo>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
    long long int h, w; cin >> h >> w;

    long long int ans = 0;

    if(h == 1 || w == 1){
        ans = 1;
    } else{
        ans = (h * w + 1) / 2;
    }

    cout << ans << "\n";
} 