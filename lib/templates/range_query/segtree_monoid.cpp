template<class T, class Monoid>
struct segtree {
    const int N;
    vector<T> tree;
    Monoid op;
    T e;
    
    segtree(int n, Monoid _op, T _e) : N(1<<(__lg(n)+1)), tree(2*N), op(_op), e(_e) {
        fill(tree.begin(), tree.end(), e);
    }
    
    void update(int pos, T x) {
        tree[pos+N] = x;
        for (int i = (pos+N)>>1; i > 0; i >>= 1) {
            tree[i] = op(tree[i*2], tree[i*2+1]);
        }
    }
    
    T query(int node, int nl, int nr, int ql, int qr) {
        if (ql > nr || qr < nl) return e;
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return op(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    
    // [l, r]
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};

// struct MaxMonoid { int operator()(int a, int b) const { return max(a, b); } };
// segtree<int, MaxMonoid> st(n, MaxMonoid{}, 0);

