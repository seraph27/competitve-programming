// Problem: P4690 [Ynoi Easy Round 2016] 镜中的昆虫
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P4690
// Time Limit: 1500
// Start: 2025/04/23 15:52:19
// mintemplate
#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}

#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif

const char nl = '\n';

struct Node {
    int x, y, t, v, id;
};

Node queries[1900005];
int q_cnt;
int vi[100005], lst[200005], pre[200005];
map<int, int> mp;
int mcnt;
struct ODTNode {
    int l, r, v;
    bool operator<(const ODTNode &o) const {
        return l < o.l;
    }
};
struct ODT {
    typedef set<ODTNode>::iterator iter;
    set<ODTNode> tr, col[200005];
    iter Insert(int l, int r, int v) {
        col[v].insert({l, r, v});
        return tr.insert({l, r, v}).first;
    }

    void Delete(int l, int r, int v) {
        col[v].erase({l, r, v});
        tr.erase({l, r, v});
    }

    iter Split(int p) {
        auto it = tr.lower_bound({p, 0, 0});
        if (it != tr.end() && it->l == p) return it;
        --it;
        int l = it->l, r = it->r, v = it->v;
        Delete(l, r, v);
        Insert(l, p - 1, v);
        return Insert(p, r, v);
    }

    int Pre(int p) {
        auto it = --tr.upper_bound({p, 0, 0});
        if(it->l < p) return p-1;
        else {
            auto it2 = col[it->v].lower_bound({p, 0, 0});
            if(it2 != col[it->v].begin()) {
                --it2;
                return it2->r;
            }
            return 0;
        }
    }
    void Assign(int l, int r, int v, int t) {
        auto itL = Split(l), itR = Split(r + 1);
        vector<int> ps;
        for(auto it = itL; it != itR; ++it) {
            if(it != itL) ps.emplace_back(it->l);
            auto nxt = col[it->v].upper_bound(*it);
            if(nxt != col[it->v].end()) {
                ps.emplace_back(nxt->l);
            }
            col[it->v].erase(*it);
        }
        tr.erase(itL, itR);
        Insert(l, r, v);
        ps.emplace_back(l);
        iter nxt = col[v].upper_bound({l, r, v});
        if(nxt != col[v].end()) {
            ps.emplace_back(nxt->l);
        }
        for(int i = 0; i < sz(ps); i++) {
            queries[++q_cnt] = {ps[i], pre[ps[i]], t, -1, 0};
            pre[ps[i]] = Pre(ps[i]);
            queries[++q_cnt] = {ps[i], pre[ps[i]], t, 1, 0};
        }
    }
} odt; 

struct fenwick {
    int bit[100005];
    fenwick() {
        memset(bit, 0, sizeof(bit));
    }
    int sum(int pos) {
        int s = 0;
        for (; pos; s += bit[pos], pos -= pos&-pos);
        return s;
    }
    int query(int l, int r) {
        return sum(r+1) - sum(l);
    }
    void update(int pos, int x) {
        for (; pos <= 100001; bit[pos] += x, pos += pos&-pos);
    }
} BIT;

void shiina_mashiro() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> vi[i];
        if(!mp[vi[i]]) mp[vi[i]] = ++mcnt;
        vi[i] = mp[vi[i]];
        pre[i] = lst[vi[i]];
        lst[vi[i]] = i;
        queries[++q_cnt] = {i, pre[i], 0, 1, 0};
        odt.Insert(i, i, vi[i]);
    }
    int a_cnt = 0;
    for(int i = 1; i <= m; i++) {
        int type; cin >> type;
        if(type == 1) {
            int l, r, x; cin >> l >> r >> x;
            if(!mp[x]) mp[x] = ++mcnt;
            x = mp[x];
            odt.Assign(l, r, x, i);
        } else {
            int l, r; cin >> l >> r;
            queries[++q_cnt] = {r, l-1, i, 1, ++a_cnt};
            queries[++q_cnt] = {l-1, l-1, i, -1, a_cnt};
        }
    }
    
    sort(queries + 1, queries + q_cnt + 1, [](const Node &a, const Node &b) {
        if(a.t != b.t) return a.t < b.t;
        return a.id < b.id;
    });

    vector<int> ans(q_cnt+1);

    auto cdq = [&](auto&&s, int l, int r) -> void {
        if(l==r) return;
        int mid = (l+r)>>1;
        s(s, l, mid);
        s(s, mid+1, r);
        int i = l, j = mid+1;
        while(j<=r) {
            while(i<=mid && queries[i].x <= queries[j].x) {
                if(!queries[i].id) {
                    BIT.update(queries[i].y + 1, queries[i].v);
                }
                i++;
            }
            if(queries[j].id) {
                ans[queries[j].id] += BIT.sum(queries[j].y + 1) * queries[j].v;
            }
            j++;
        }
        for(int k = l; k < i; k++) if(!queries[k].id) {
            BIT.update(queries[k].y + 1, -queries[k].v);
        }
        inplace_merge(queries + l, queries + mid + 1, queries + r + 1, [](const Node &a, const Node &b) {
            if(a.x != b.x) return a.x < b.x;
            return a.id < b.id;
        });
    };

    cdq(cdq, 1, q_cnt);

    for(int i = 1; i <= a_cnt; i++) cout << ans[i] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

