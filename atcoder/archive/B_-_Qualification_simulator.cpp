#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int bcount = 0;
    int yesnum = 0;

    for(int i = 0; i < s.length(); i++){
        if (s[i] == 'c' || yesnum >= a + b){
            cout << "No" << "\n";
        } else if(s[i] == 'b'){
            bcount++;
            if(bcount <= b){
                cout << "Yes" << "\n";
                yesnum++;
            } else{
                cout << "No" << "\n";
            }
        } else if(s[i] == 'a'){
            cout << "Yes" << "\n";
            yesnum++;
        }
    }
} 