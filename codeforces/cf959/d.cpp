#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef SERAPH
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
const int INF = 0x3f3f3f3f;

struct dsu{
    vector<int> p, sz;
    dsu(int n) : sz(n, 1), p(n) {
        for(int i = 0; i < n; i++) p[i]=i;
    }
    int find(int v) {
        return p[v]==v ? v : (p[v]=find(p[v]));
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u!=v) {
            if(sz[u]<sz[v]) swap(u, v);
            p[v]=u;
            sz[u]+=sz[v];
        }
    } 
    bool same(int u, int v) {
        return find(u)==find(v);
    }
};

void seraph() {
    int n; cin >>n;
    vector<int> vi(n);
    for(auto&a: vi) cin >> a;
    dsu uf(n);
    vector<pii> ans;
    for(int i = n-1; i>=1; i--){
        vector<int> has(n, -1);
        for(int j = 0; j < n; j++) {
            if(uf.find(j)!=j) continue;
            int now = has[vi[j]%i];
            if(now!=-1) {
                ans.pb({now+1, j+1});
                uf.merge(now, j);
                break;
            }
            has[vi[j]%i]=j;
        }
    }
    cout<<"Yes"<<nl;
    reverse(all(ans));
    for(auto&[fi, se]:ans) cout<<fi <<" "<<se <<nl;

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) seraph();
}

