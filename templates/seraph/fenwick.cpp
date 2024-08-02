template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    T query(int pos) {
        T s = 0;
        for (++pos; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return query(r) - query(l-1);
    }
    void update(int pos, T x) {
        for (++pos; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};
