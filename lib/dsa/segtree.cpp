struct segtree {
    const int N; vector<T> tree;
    segtree(int n) : N(1<<(__lg(n)+1)), tree(2*N) {}
    void update(int pos, T x) {
        for (int i = pos+N; i > 0; i >>= 1) ckmax(tree[i], x);
    }
    T query(int node, int nl, int nr, int ql, int qr) {
        if (ql > nr || qr < nl) return 0;
        if (ql <= nl && nr <= qr) return tree[node];
        int mid = (nl+nr)/2;
        return max(query(node*2, nl, mid, ql, qr), query(node*2+1, mid+1, nr, ql, qr));
    }
    T query(int l, int r) { return query(1, 0, N-1, l, r); }
};

//bottom up ^



// const int SZ = 1<<19;
// ll n, a[SZ], t[SZ<<1];

// void build(ll l, ll r, ll p) {
//     if(l == r) {t[p] = a[l]; return;}
//     ll m = (l+r)>>1;
//     build(l, m, p<<1), build(m+1, r, (p<<1)|1);
//     t[p] = max(t[p<<1], t[(p<<1)|1]);
// }

// void update(ll tl, ll tr, ll p, ll pos, ll val) {
//     if(tl == tr) {t[p] = val; return;}
//     ll m = (tl+tr)>>1;
//     if(pos<=m) update(tl, m, p<<1, pos, val);
//     else update(m+1, tr, (p<<1)|1, pos, val);
//     t[p] = max(t[p<<1], t[(p<<1)|1]);
// }

// ll getmx(ll l, ll r, ll tl, ll tr, ll p) {
//     if(l<=tl && tr<=r) return t[p];
//     ll m = (tl+tr)>>1;
//     ll mx = 0;
//     if(l<=m) ckmax(mx, getmx(l, r, tl, m, p<<1));
//     if(r>m) ckmax(mx, getmx(l, r, m+1, tr, (p<<1)|1));
//     return mx;
// }