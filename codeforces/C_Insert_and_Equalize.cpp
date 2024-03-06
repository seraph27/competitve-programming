#include <bits/stdc++.h>
#define ll long long
#define ar array
#define db double
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.f); cerr << ','; __print(x.s); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const int mod = 1e9+7;
const char nl = '\n';

int gcd(int a, int b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

void test_case() {
    int n; cin >> n;
    vector<ll> vi(n);
    for(auto&a: vi) cin >> a;
    if(vi.size() == 1) {
        cout << 1 << nl;
        return;
    }
    sort(all(vi));
    vector<ll> diff(n-1);
    for(int i = 0; i < n-1; i++){
        diff[i] = vi[i+1]-vi[i];
    }
    ll gcdd = diff[0];
    for(int i = 1; i < n-1; i++){
        gcdd = gcd(diff[i], gcdd);
    }

    int cnt = 1;
    ll tot = 0;
    for(int i = 0; i < diff.size(); i++){
        tot+= diff[i]*cnt;
        cnt++;
    } 
    ll res = 1;
    for(int i = n-1; i > 0; i--){
        if(vi[i]-vi[i-1] == gcdd){
            res++;
        } else {
            break;
        }
    }
    cout << tot/gcdd + res << nl;
    debug(gcdd);
    debug(vi, diff);
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}
