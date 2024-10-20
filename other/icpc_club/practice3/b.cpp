#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ll long long
#define pb push_back
using namespace std;

#ifdef MISAKA
struct _debug {
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', 
        __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ",
        _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif
const char nl = '\n';

template<typename T> struct fenwick {
    int n; vector<T> bit;
    fenwick(int a) : n(a), bit(a+1) {}
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
        for (; pos <= n; bit[pos] += x, pos += pos&-pos);
    }
};

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> vi(n);
    for(int i = 0; i < n; i++) {
        cin >> vi[i].first;
        --vi[i].first; 
    }
    for(int i = 0; i < n; i++) {
        cin >> vi[i].second;
        --vi[i].second;
    }

    auto cnt_inv = [&](vector<int> &v) -> ll {
        ll ans = 0;
        fenwick<ll> bit(sz(v));
        for(int i = 0; i < sz(v); i++) {
            ans += bit.query(v[i], sz(v)-1);
            bit.update(v[i], 1);
        }
        return ans;
    };
    sort(all(vi));
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        a[i] = vi[i].first;
        b[i] = vi[i].second;
        mp[a[i]] = b[i];
    } 
    ll inv_a = cnt_inv(a), inv_b = cnt_inv(b);
    if((inv_a&1) != (inv_b&1)) {
        cout << "No" << nl;
        return;
    }
    debug(inv_a, inv_b);
    cout << "Yes" << nl;
    if(inv_a < inv_b) swap(inv_a, inv_b);
    ll need = inv_a - inv_b;
    need/=2;
    vector<ll> ans;
    vector<ll> used(n);
    for(int i = n-1; i >= 1; i--) {
        if(need-i>=0) {
            ans.pb(i);
            need-=i;
            used[i] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) ans.pb(i);
    }
    vector<int> temp1, temp2;
    for(int i = 0; i < n; i++) {temp1.pb(ans[i]); cout << ans[i]+1 << " ";}
    cout << nl;
    for(int i = 0; i < n; i++) {temp2.pb(mp[ans[i]]); cout << mp[ans[i]]+1 << " ";}
    cout << nl;
    debug(cnt_inv(temp1), cnt_inv(temp2));
    debug(vi);
    debug(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while(t--) solve();
}
