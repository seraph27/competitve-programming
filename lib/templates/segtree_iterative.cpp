struct segtree {
    int n; vector<int> t;
    segtree(int siz) {
        n = siz;
        t.assign(2 * n, 0);
        for(int i = n-1; i>0; i--) t[i] = min(t[i<<1], t[i<<1|1])
    }

    void update(int p, int val) {
        for(t[p+=n] = val; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
    }

    //[l, r)
    int query(int l, int r) {
        int res = 4e18;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) ckmin(res, t[l++]);
            if(r&1) ckmin(res, t[--r]);
        }
        return res;
    }
};
