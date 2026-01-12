template<class T, class Monoid, class LazyApply, class LazyCombine>
struct segtree {
    const int N;
    vector<T> tree, lazy;
    vector<int> size;
    Monoid op;
    T e;
    LazyApply apply_lazy;
    LazyCombine combine_lazy;
    T lazy_e;
    
    segtree(int n, Monoid _op, T _e, LazyApply _apply_lazy, LazyCombine _combine_lazy, T _lazy_e) 
        : N(1<<(__lg(n)+1)), tree(2*N), lazy(2*N), size(2*N), 
          op(_op), e(_e), apply_lazy(_apply_lazy), combine_lazy(_combine_lazy), lazy_e(_lazy_e) {
        fill(tree.begin(), tree.end(), e);
        fill(lazy.begin(), lazy.end(), lazy_e);
        for (int i = 0; i < n; i++) size[i+N] = 1;
        for (int i = N-1; i >= 1; i--) size[i] = size[i*2] + size[i*2+1];
    }
    
    void push(int node) {
        if (lazy[node] != lazy_e) {
            tree[node] = apply_lazy(tree[node], lazy[node], size[node]);
            if (node < N) {
                lazy[node*2] = combine_lazy(lazy[node*2], lazy[node]);
                lazy[node*2+1] = combine_lazy(lazy[node*2+1], lazy[node]);
            }
            lazy[node] = lazy_e;
        }
    }
    
    void update(int node, int nl, int nr, int ql, int qr, T v) {
        push(node);
        if (ql > nr || qr < nl) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] = combine_lazy(lazy[node], v);
            push(node);
            return;
        }
        int mid = (nl+nr)/2;
        update(node*2, nl, mid, ql, qr, v);
        update(node*2+1, mid+1, nr, ql, qr, v);
        tree[node] = op(tree[node*2], tree[node*2+1]);
    }
    
    T query(int node, int nl, int nr, int ql, int qr) {
        push(node);
        if (ql > nr || qr < nl) return e;
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return op(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    
    // [l, r]
    void update(int l, int r, T v) { update(1, 0, N-1, l, r, v); }
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};

// struct SumMonoid { T operator()(T a, T b) const { return a + b; } };
// struct AddLazyApply { T operator()(T val, T lazy_val, int sz) const { return val + lazy_val * sz; } };
// struct AddLazyCombine { T operator()(T a, T b) const { return a + b; } };
// segtree<T, SumMonoid, AddLazyApply, AddLazyCombine> st(n, SumMonoid{}, 0, AddLazyApply{}, AddLazyCombine{}, 0);

