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

const int INF = 1001001001;
const int mod = 1e9+7;
const char nl = '\n';

vector<bool> dp(100005, false);

void precalc(){
    vector<int> vi;
    for(int mask = 1; mask < 32; mask++){
        int sum = 0;
        for(int i = 0; i < 5; i++){
            sum = sum*10 + (mask >> i & 1);
        }
        vi.push_back(sum);
    }
    dp[1] = 1;
    for(int i = 1; i <= 100005; i++){
        if(dp[i]){
            for(int j : vi){
                if(i*j <= 100005) dp[i*j] = 1;
            }
        }
    }
}

void test_case() {
    int n; cin >> n;
    cout << (dp[n] ? "YES" : "NO") << nl;
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    precalc();
    int t = 1;
    cin >> t;
    while (t--) test_case();
}



// void test_case() {
//     int n; cin >> n;

//     vector<int> choices;
//     for(int mask = 0; mask < (1 << 5); mask++){
//         string s = "";
//         for(int i = 0; i < 5; i++){
//             if(mask & (1 << i)) s+="1";
//             else s+="0";
//         }
//         choices.push_back(stoi(s));
//     }

//     bool check = 0;
//     while(n>1){
//         for(int i = 1; i < choices.size()-1; i++){
//             if(n%choices[i]==0 && choices[i] != 1){
//                 n/=choices[i];
//                 check = 1;

//             } 
//         }
//         if(!check) break;
//         check = 0;
//     }
//     bool ok = 1;
//     for(auto&a: to_string(n)){
//         if(a!='0' && a!='1') ok = 0;
//     }
//     cout << (ok ? "YES" : "NO") << nl;
// }
