#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const char nl = '\n';

const int MX = 8000;
bitset<MX> bs[MX];
int cnt[MX];
int ord[MX];
string s;
pair<int,int> res[MX];

struct DSU {
    int f[MX], siz[MX];

    DSU() {}

    void init(int n) {
        iota(f, f + n, 0);
        fill(siz, siz + n, 1);
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
} uf;

void shiina_mashiro() {
    int n; cin >> n;
    bool ok = true;

    for(int i = 0; i < n; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        bs[i] = bitset<MX>(s);
        cnt[i] = bs[i].count();
        if(!bs[i].test(i)) ok = false;
    }

    iota(ord, ord + n, 0);
    sort(ord, ord + n, [&](int i, int j) { return cnt[i] < cnt[j]; });

    int idx = 0;
    for(int i = 0; ok && i < n; i++) {
        int u = ord[i];
        bitset<MX> curr(bs[u]);
        int reach = cnt[u];
        for(int j = i - 1; j >= 0; j--) {
            int v = ord[j];
            if(cnt[v] >= reach) continue;
            if((curr & bs[v]) == bs[v]) {
                res[idx++] = {u, v};
                curr &= ~bs[v];
                reach = curr.count();
            }
        }
        if(curr.count() != 1 || !curr.test(u)) ok = false;
    }

    uf.init(n);
    for(int i = 0; i < idx; i++) uf.merge(res[i].first, res[i].second);

    if(!ok || uf.size(0) != n || idx != n - 1) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        for(int i = 0; i < idx; i++) cout << res[i].first + 1 << " " << res[i].second + 1 << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}
