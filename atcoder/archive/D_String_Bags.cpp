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
const int INF = 1001001001;
const char nl = '\n';


void test_case() {
    string t; int n; cin >> t >> n;
    int tsize = t.size();
    vector<vector<int>> dp(n+5, vector<int>(tsize+5, INF));  //dp[ith bag][letters]
    dp[0][0] = 0;
    for(int i = 0; i < n+1; i++){
        for(int mv = 0; mv < tsize+1; mv++) {dp[i+1][mv] = dp[i][mv];}
        int a; cin >> a; //for each letter
        while(a>0){
            a--;    
            string s; cin >> s;
            int slen = s.size(); 
            for(int k = 0; k < t.size()+1; k++){ //compare to dp[i][k]
                if(slen+k > tsize) continue;   
                bool ok = true;
                for(int ii = 0; ii < slen; ii++) {
                    if(s[ii]!=t[k+ii]){ //check each char
                        ok = false; 
                        break;
                    }
                }
                if(ok) dp[i+1][k+slen] = min(dp[i+1][k+slen], dp[i][k]+1);
            }
        }   
    }   

    cout << (dp[n][tsize] == INF ? -1 : dp[n][tsize]) << nl;
    
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}



// tle brute force 
// void test_case() {
//     string goal; cin >> goal;
//     int n; cin >> n;
//     vector<tuple<string, int, int>> vi;
//     int ans = INT_MAX;
//     while(n--){
//         int a; cin >> a;
//         vector<string> wordbag(a);
//         for(int i = 0; i < a; i++){
//             string s; cin >> s;
//             wordbag[i]=s;
//             vi.emplace_back(make_tuple(s, s.length(), 1));          
//         }

//         for(auto&ss: wordbag){
//             for(int k = 0; k < (int)vi.size(); k++){
//                 auto [st, curlen, cnt] = vi[k];
//                 if(curlen+ss.length()<=goal.length()){
//                     bool ok2 = 1;
//                     for(int j = 0; j < (int)ss.length(); j++){
//                         if(ss[j]==goal[j+curlen]) ok2 = 0;                                                  
//                     }
//                     if(ok2) vi.emplace_back(make_tuple(st+ss, curlen+ss.length(), cnt+1));
//                 }

//             }
//         }
//         for(auto [aa, b, c] : vi){
//             //cout << aa << " " << b << " " << c << nl;
//             if(b==goal.length()){
//                 ans = min(ans, c);
//             } 
//         }
        
//     }
//     cout << (ans==INT_MAX ? -1 : ans ) << nl;      
// }
