const int hash_mod = 1e9+7;
int binpow(int a, int b) {
    int r = 1;
    for (; b > 0; b >>= 1, a = (long long)a*a%hash_mod) if (b&1) r = (long long)r*a%hash_mod;
    return r;
}
const int b_N = 2;
bool init_ = 0;
array<int, b_N> bases;
void init() {
    for (int i = 0; i < b_N; i++) {
        bases[i] = rint(2, hash_mod-1);
    }
}
template<typename T> struct Hash {
    array<vector<int>, b_N> pref, inv;
    Hash(const T& s) {
        if (!init_) init(), init_ = 1;
        int n = s.size();
        for (int i = 0; i < b_N; i++) {
            pref[i].resize(n), inv[i].resize(n);
            inv[i][n-1] = binpow(binpow(bases[i], n-1), hash_mod-2);
            for (int j = n-2; j >= 0; j--) inv[i][j] = (long long)inv[i][j+1] * bases[i] % hash_mod;
            for (int j = 0, b = 1; j < n; j++, b = (long long)b * bases[i] % hash_mod) {
                pref[i][j] = (j?pref[i][j-1]:0) + (long long)b*(int(s[j])+2)%hash_mod;
                if (pref[i][j] >= hash_mod) pref[i][j] -= hash_mod;
            }
        }
    }
    array<int, b_N> query(int l, int r) const {
        array<int, b_N> ret;
        for (int i = 0; i < b_N; i++) {
            ret[i] = pref[i][r] - (l?pref[i][l-1]:0);
            if (ret[i] < 0) ret[i] += hash_mod;
            ret[i] = (long long)ret[i] * inv[i][l] % hash_mod;
        }
        return ret;
    }
};