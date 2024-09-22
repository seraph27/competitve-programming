template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a+1), bit(a+1) {}
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos < n; bit[pos] += x, pos += pos&-pos);
    }
};

//outside is all 0-indexed, inclusive, so l, r -> l, r;
//don't add 1 to update;
