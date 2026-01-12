template<class T, class Monoid>
struct segtree {
    int n;
    vector<T> t;
    Monoid op;
    T e;
    
    segtree(int siz, Monoid _op, T _e) : n(siz), op(_op), e(_e) {
        t.assign(2 * n, e);
    }
    
    void build() {
        for(int i = n-1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
    }
    
    void update(int p, T val) {
        for(t[p += n] = val; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
    }
    
    // [l, r)
    T query(int l, int r) {
        T res = e;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res = op(res, t[l++]);
            if(r&1) res = op(res, t[--r]);
        }
        return res;
    }
};

// struct MinMonoid { int operator()(int a, int b) const { return min(a, b); } };
// segtree<int, MinMonoid> st(n, MinMonoid{}, numeric_limits<int>::max());

