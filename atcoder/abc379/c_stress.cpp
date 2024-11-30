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
void test_case() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	for (int &x : a) cin >> x;
	ll stones = 0;
	for (int &x : b) cin >> x, stones += x;
	if (stones != n) {
		cout << -1 << '\n';
		return;
	}
	auto prog = [](int l, int r) {
		return ((ll)l+r)*(r-l+1)/2;
	};
	vector<int> idx(m);
	iota(all(idx), 0);
	sort(all(idx), [&](int x, int y) { return a[x] < a[y]; });
	int on = 1;
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		if (a[idx[i]] > on) {
			cout << -1 << '\n';
			return;
		}
		ans += prog(on, on + b[idx[i]] - 1) - (ll)a[idx[i]] * b[idx[i]];
		on += b[idx[i]];
	}
	cout << ans << '\n';


}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
//    cin >> t;
    while (t--) test_case();
}

