struct trie {
    static const int MX = 1e6 + 5;
    int cnt;
    int nex[MX][26];
    bool exist[MX];

    trie() { init(); }

    void init() {
        cnt = 0;
        memset(nex, -1, sizeof(nex));
        memset(exist, 0, sizeof(exist));
    }

    void insert(const string &s) {
        int vtx = 0;
        for (char c : s) {
            int d = c - 'a';
            int &nx = nex[vtx][d];
            if (nx == -1) nx = ++cnt;
            vtx = nx;
        }
        exist[vtx] = true;
    }

    string search(string &s) {
        int vtx = 0; string ans;
        for (char c : s) {
            int d = c - 'a';
            ans += c;
            int nx = nex[vtx][d];
            if (nx == -1) return s;
            vtx = nx;
            if (exist[vtx]) return ans;
        }
        return s;
    }
};
