template<class T> struct segtree {
    const int N; vector<T> tree, lazy;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N), lazy(2*N) {}
    void push(int node) {
        if (lazy[node]) {
            tree[node] += lazy[node];
            if (node < N) lazy[node*2] += lazy[node], lazy[node*2+1] += lazy[node];
            lazy[node] = 0;
        }
    }
    void update(int node, int nl, int nr, int ql, int qr, T v) {
        push(node);
        if (ql > nr || qr < nl) return;
        if (ql <= nl && nr <= qr) {
            lazy[node] += v, push(node);
            return;
        }
        int mid = (nl+nr)/2;
        update(node*2, nl, mid, ql, qr, v);
        update(node*2+1, mid+1, nr, ql, qr, v);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
    T query(int node, int nl, int nr, int ql, int qr) {
        if (ql > nr || qr < nl) return numeric_limits<T>::max();
        push(node);
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return min(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    void update(int l, int r, T v) { update(1, 0, N-1, l, r, v); }
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};
