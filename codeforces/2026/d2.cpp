#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pb push_back
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

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
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    
    std::vector<i64> s0(n + 2), s1(n + 2), ss(n + 2);
    for (int i = 0; i <= n; i++) {
        s0[i + 1] = s0[i] + pre[i];
        s1[i + 1] = s1[i] + pre[i] * i;
    }
    for (int i = 0; i <= n; i++) {
        ss[i + 1] = ss[i] + s0[i];
    }
    debug(s0, s1, ss);
    auto query = [&](i64 x) {
        i64 lo = 0, hi = n;
        while (lo < hi) {
            int u = (lo + hi + 1) / 2;
            if (x >= 1LL * u * (n + n - u + 1) / 2) {
                lo = u;
            } else {
                hi = u - 1;
            }
        }
        i64 res = 0;
        
        i64 u = lo;
        res += s0[n + 1] * u;
        res -= ss[u];
        res -= s0[u] * (n + 1);
        res += s1[u];
        x -= 1LL * u * (n + n - u + 1) / 2;
        res += s0[u + x + 1] - s0[u];
        res -= pre[u] * (x + 1);
        return res;
    };
    
    int q;
    std::cin >> q;
    
    while (q--) {
        i64 l, r;
        std::cin >> l >> r;
        l--;
        
        std::cout << query(r) - query(l) << "\n";
    }
    
    return 0;
}
