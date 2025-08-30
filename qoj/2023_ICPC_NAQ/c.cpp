#ifdef MISAKA
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define int long long
#define double long double
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
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

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
const double eps = 1e-12;

void shiina_mashiro() {
    int n, k; cin >> n >> k;
    vector<ar<int, 2>> food(n + 1);
    int S = 0;
    for(int i = 1; i <= n; i++) {
        cin >> food[i][0] >> food[i][1];
        S += food[i][0];
    }
    
    auto can = [&](double x) -> bool {
        priority_queue<ar<double, 2>, vector<ar<double, 2>>, greater<ar<double, 2>>> pq;
        for (int i = 1; i <= n; ++i) {
            pq.push({(double)food[i][1], (double)food[i][0]});
            double need = (double)k * x;
            while(!pq.empty() && pq.top()[0] < i) {
                pq.pop();
            }
            while(need > eps && !pq.empty()) {
                auto current_food = pq.top();
                pq.pop();
                double expiry_date = current_food[0];
                double available = current_food[1];
                double take = min(need, available);
                need -= take;
                available -= take;
                if (available > eps) {
                    pq.push({expiry_date, available});
                }
            }
            
            if (need > eps) {
                return false;
            }
        }
        return true;
    };

    if(!can(1e-9)) { 
        cout << -1 << nl;
        return;
    }

    double l = 0, r = (double)S / k + 1;
    for(int iter = 0; iter < 100; ++iter) {
        double mid = l + (r - l) / 2;
        if (mid < eps) { 
             l = mid;
             continue;
        }
        if(can(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(20) << l << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}
