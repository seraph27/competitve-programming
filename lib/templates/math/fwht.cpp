void fwht(vector<ll>& a, bool inv) {
	int w = __lg(sz(a));
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < 1 << w; j += 1 << (i+1)) {
			for (int k = 0; k < 1 << i; k++) {
				auto l = a[j+k], r = a[(j+k) ^ 1 << i];
				a[j+k] = (l + r) >> inv;
				a[(j+k) ^ 1 << i] = (l - r) >> inv;
			}
		}
	}
}