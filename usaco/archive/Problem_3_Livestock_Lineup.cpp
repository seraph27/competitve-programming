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

void test_case() {
    int n; cin >> n;
    vector<vector<int>> adj(8);
    map<string, int> cows = {
        {"Beatrice" , 0},
        {"Belinda" , 1},
        {"Bella" , 2},
        {"Bessie" , 3},
        {"Betsy" , 4},
        {"Blue" , 5},
        {"Buttercup" , 6},
        {"Sue" , 7},
    };
    vector<string> cowskey = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

    string s = "";
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        string s1 = s.substr(0, s.find(" "));
        string s2 = s.substr(s.rfind(" ") + 1);
        adj[cows[s1]].push_back(cows[s2]);
        adj[cows[s2]].push_back(cows[s1]);
    }
    debug(adj);

    vector<bool> seen(8, false);

    for(int i = 0; i < adj.size(); i++){
        if(!seen[i]){
            if(adj[i].size() <= 1){
                cout << cowskey[i] << nl;
                seen[i] = true;
                
                if(adj[i].size() == 1 && adj[adj[i][0]].size() == 1){
                    cout << cowskey[adj[i][0]] << nl;
                    seen[adj[i][0]] = true;
                } 
                if(adj[i].size() == 1 && adj[adj[i][0]].size() > 1){
                    cout << cowskey[adj[i][0]] << nl;
                    seen[adj[i][0]] = true;
                    vector<int> nextchain = adj[adj[i][0]];
                    debug(nextchain);
                    while(nextchain.size() >= 2){
                        for(auto &a: nextchain){
                            if(!seen[a]){
                                cout << cowskey[a] << nl;
                                seen[a] = true;
                                nextchain = adj[a];
                            }
                        }
                    }
                }
            } 
        }
    }
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    freopen("lineup.in","r",stdin); freopen("lineup.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
