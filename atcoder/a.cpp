#include<bits/stdc++.h>
#include <string> 
#include <algorithm> 

using namespace std;
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pi=pair<int,int>;
using vi=vc<int>;
 
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;

	int n = s.size()+1;
	vi v(n);

	for(int i = 0; i < n-1; i++){
		if(s[i] == '<'){
			if(v[i+1] < v[i] + 1){
				v[i+1] = v[i] + 1;
			}
		} 
	}

	for(int i = n-2; i >= 0; i--){	
		if(s[i] == '>'){
			if(v[i] < v[i+1] + 1){
				v[i] = v[i+1] + 1;
			}
		} 
		
	}

	cout << accumulate(all(v), int(0)) << endl;
}

