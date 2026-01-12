template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
    
    T sum(int pos) {
        T s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    // [l, r]
    T query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, T x) {
        pos++;
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
    
    // find k-th smallest (1-indexed k), returns 0-indexed position
    int kth(T k) {
        int pos = 0;
        for (int j = __lg(n); j >= 0; j--) {
            if (pos + (1 << j) <= n && bit[pos + (1 << j)] < k) {
                pos += 1 << j;
                k -= bit[pos];
            }
        }
        return pos;
    }
};
//outside is all 0-indexed, inclusive, so [l, r]
//don't add 1 to update;
