struct trie {
    int cnt{};
    int nex[100001][26]{};
    bool exist[100001]{};

    void insert(string&s) {
        int vtx = 0;
        for(char c : s) {
            int d = c-'a';
            auto &nx = nex[vtx][d];
            if(!nx) {
                nx = ++cnt;
            }
            vtx = nx;
        }
        exist[vtx] = 1;
    }

    string search(string&s) {
        int vtx = 0;
        string ans;
        for(char c : s) {  
            int d = c-'a';
            ans+=c;
            auto &nx = nex[vtx][d];
            if(!nx) return s;
            vtx = nx;  
            if(exist[vtx]) return ans;
        }
        return s;
    }
};