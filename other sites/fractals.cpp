#include <bits/stdc++.h>
#define ll long long
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
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
const int INF = 1001001001;
const ll INFLL = 1LL<<60;

void shiina_mashiro() {
    int n; cin >> n;
    vector<string> fractal(256);
    fractal[0] = "/\\";
    string padding = string(n, ' ');
    int spaces = 0;
    int cnt = 1;
    int front = n;
    for(int i = 1; i < n; i++){
        fractal[i] = fractal[i-cnt] + string((spaces*2-2) >= 0 ? spaces*2-2 : 0, ' ') + fractal[i-cnt];
        spaces--;
        cout << padding;
        if(spaces <= 0){
            cnt*=2;
            spaces = cnt; 
        } 
    }
    for(int i = 0; i < n; i++){
        cout << string(front, ' ') + fractal[i] << nl;
        front--;
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}