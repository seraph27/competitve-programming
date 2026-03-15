#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 8000;
bitset<N> bs[N];
int cnt[N], ord[N], p[N];
pair<int, int> res[N];

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool ok = 1;
		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			reverse(begin(s), end(s));
			bs[i] = bitset<N>(s);
			cnt[i] = bs[i].count();
			ok &= bs[i][i];
		}
		iota(ord, ord+n, 0);
		sort(ord, ord+n, [&](int i, int j){ return cnt[i] < cnt[j]; });
		int idx = 0;
		for(int i=0; i<n && ok; i++){
			int x = ord[i];
			bitset<N> cur(bs[x]);
			int rem = cnt[x];
			for(int j=i-1; j>=0 && ok; j--){
				int y = ord[j];
				if(cnt[y] >= rem) continue;
				if((cur & bs[y]) == bs[y]){
					res[idx++] = make_pair(x,y);
					cur &= (~bs[y]);
					rem = cur.count();
				}
			}
			if(cur.count() != 1 || !cur[x]){
				ok = 0;
			}
		}
		ok &= idx == n-1;
		iota(p, p+n, 0);
		for(int i=0; i<n-1; i++){
			auto [x,y] = res[i];
			int go = p[y];
			for(int j=0; j<n; j++){
				if(p[j] == go) p[j] = p[x];
			}
		}
		for(int i=0; i<n; i++){
			ok &= p[i] == p[0];
		}

		if(ok){
			cout << "Yes\n";
			for(int i=0; i<n-1; i++){
				auto [x,y] = res[i];
				cout << x+1 << ' ' << y+1 << '\n';
			}
		}
		else{
			cout << "No\n";
		}
	}

}
