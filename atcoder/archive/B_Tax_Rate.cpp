#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 
#include <typeinfo>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int a; cin >> a;

    int d = floor(a / 1.08);

    if(floor(d * 1.08) == a){
        cout << d << "\n";
    } else if(floor((d+1) * 1.08) == a){
        cout << d+1 << "\n";
    } else{
        cout << ":(" << "\n";
    }
    

} 