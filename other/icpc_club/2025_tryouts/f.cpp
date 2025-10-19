#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
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

void solve() {
    int a, b, c; cin >> a >> b >> c;

    vector<int> digits;
    auto tmp = a;
    while(tmp) {
        digits.pb(tmp % 10);
        tmp /= 10;
    }
    reverse(all(digits));

    int mn = 1e18, mx = -1e18;
    
    int sum = b + c;
    for(int msk = 0; msk < (1 << sz(digits)); msk++) {
        int ssum = 0;
        for(int i = 0; i < sz(digits); i++) if(msk >> i & 1) ssum += digits[i];
        if(ssum == sum) {
            int val = 0;
            for(int i = 0; i < sz(digits); i++) if(!(msk >> i & 1)) val = val * 10 + digits[i];
            ckmin(mn, val);
            ckmax(mx, val);
        }
    }

    if(mn == 1e18) {
        cout << -1 << " ";
        cout << fixed << setprecision(5) << (double)a << nl;
        cout << -1 << " ";
        cout << fixed << setprecision(5) << (double)a << nl;
        return;
    }
    string smn, smx;
    
//    debug(mn, mx);
//    for(auto tmp = a; tmp; tmp /= 10) {
 //       auto s = to_string(mn);
//        auto c = (tmp % 10) + '0';
//        if(s.find(c) == string::npos)smn.pb(c);
//    }
//    for(auto tmp = a; tmp; tmp /= 10) {
//        auto s = to_string(mx);
//        auto c = (tmp % 10) + '0';
//        if(s.find(c) == string::npos)smx.pb(c);
//   }
//    reverse(all(smn));
//    reverse(all(smx));
    

    debug(smn, smx);
    //try to remove subset of b + c;
    int mask0 = 0;
    for(int d : digits) mask0 |= 1 << d;

    vector<int> cnt(13);
    cnt[2]=1; cnt[3]=2; cnt[4]=3; cnt[5]=4; cnt[6]=5; cnt[7]=6; cnt[8]=5; cnt[9]=4; cnt[10]=3; cnt[11]=2; cnt[12]=1;

    vector<int> val(1 << 10), digsum(1 << 10);
    for(int msk = 0; msk < (1 << 10); msk++) {
        int add = 0, s = 0;
        for(int d = 1; d <= 9; d++) if(msk >> d & 1) { 
            add = add * 10 + d;
            s += d;
        }
        val[msk] = add;
        digsum[msk] = s;
    }

    vector<db> dpmin(1 << 10, -1), dpmax(1 << 10, -1);
    auto fmin = [&](auto&&ss, int m) -> db {
        if(dpmin[m] >= -0.5) return dpmin[m];
        db tot = 0;
        for(int s = 2; s <= 12; s++) {
            db best = 1e100;
            bool ok = false;
            for(int sub = m; sub; sub = (sub - 1) & m) if(digsum[sub] == s) {
                ok = 1;
                ckmin(best, ss(ss, m ^ sub));
            }
            if(!ok) best = val[m];
            tot += cnt[s] * best;
        }
        return dpmin[m] = tot / (db)36;
    };

    auto fmax = [&](auto &&ss, int m) -> db {
        if(dpmax[m] >= -0.5) return dpmax[m];
        db tot = 0;
        for(int s = 2; s <= 12; s++) {
            db best = -1e100;
            bool ok = false;
            for(int sub = m; sub; sub = (sub - 1) & m) if(digsum[sub] == s) {
                ok = 1;
                ckmax(best, ss(ss, m ^ sub));
            }
            if(!ok) best = val[m];
            tot += cnt[s] * best;
        }
        return dpmax[m] = tot / (db)36;
    };

    dpmin[0] = 0; dpmax[0] = 0;
    fmin(fmin, mask0);
    fmax(fmax, mask0);

    int need = sum;

    int bm = 0; db emn = 1e100; bool anym = false;
    for(int sub = mask0; sub; sub = (sub - 1) & mask0) if (digsum[sub] == need) {
        anym = true;
        db ev = fmin(fmin, mask0 ^ sub);
        debug(ev, sub);
        if (ev + 1e-15 < emn) { emn = ev; bm = sub; }
    }
    if (!anym) {
        cout << -1 << " " << fixed << setprecision(5) << (db)val[mask0] << nl;
    } else {
        string mv;
        for(int d = 1; d <= 9; d++) if (bm >> d & 1) mv.pb(char('0' + d));
        cout << mv << " " << fixed << setprecision(5) << emn << nl;
    }
    
    int bx = 0; db emx = -1e100; bool anyx = false;
    for(int sub = mask0; sub; sub = (sub - 1) & mask0) if (digsum[sub] == need) {
        anyx = true;
        db ev = fmax(fmax, mask0 ^ sub);
        if (ev > emx + 1e-15) { emx = ev; bx = sub; }
    }
    if (!anyx) {
        cout << -1 << " " << fixed << setprecision(5) << (db)val[mask0] << nl;
    } else {
        string mv;
        for(int d = 1; d <= 9; d++) if (bx >> d & 1) mv.pb(char('0' + d));
        cout << mv << " " << fixed << setprecision(5) << emx << nl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    while (t--) solve();
}
