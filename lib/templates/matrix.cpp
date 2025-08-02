template<typename T, class Add, class Mul>
struct matrix {
    int n;
    vector<T> a;
    Add add;
    Mul mul;
    T add_id;
    T mul_id;
    matrix(int _n, Add _add, Mul _mul, T _add_id, T _mul_id)
        : n(_n), a(n * n), add(_add), mul(_mul), add_id(_add_id), mul_id(_mul_id) {}
    static matrix identity(int n, Add add, Mul mul, T add_id, T mul_id) {
        matrix m(n, add, mul, add_id, mul_id);
        for (int i = 0; i < n; ++i) m(i,i) = mul_id;
        return m;
    }
    T& operator()(int i, int j) { return a[i * n + j]; }
    T operator()(int i, int j) const { return a[i * n + j]; }
    matrix operator*(const matrix &rhs) const {
        matrix res(n, add, mul, add_id, mul_id);
        for (int i = 0; i < n * n; ++i) res.a[i] = add_id;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < n; ++k) {
                T x = (*this)(i,k);
                for (int j = 0; j < n; ++j) {
                    res(i,j) = add(res(i,j), mul(x, rhs(k,j)));
                }
            }
        }
        return res;
    }
    matrix pow(long long e) const {
        matrix base = *this;
        matrix res = identity(n, add, mul, add_id, mul_id);
        while (e > 0) {
            if (e & 1) res = res * base;
            base = base * base;
            e >>= 1;
        }
        return res;
    }
    vector<T> apply(const vector<T> &v) const {
        vector<T> out(n, add_id);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                out[i] = add(out[i], mul((*this)(i,j), v[j]));
            }
        }
        return out;
    }
};
