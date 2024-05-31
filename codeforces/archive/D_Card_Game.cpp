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
    char trump; cin >> trump;
    vector<string> vi(2*n);

    map<char, vector<string>> howmany; 
    vector<string> trumpstring;
    for(auto&a: vi){
        cin >> a;
        if(a[1] != trump){
            howmany[a[1]].push_back(a);     
        } else{
            trumpstring.push_back(a);
        }
    }

    int trumpnum = trumpstring.size();
    int odd = 0;
    for(auto&a: howmany){
        if(a.second.size()%2 == 1){
            odd++;
        }
    }

    if(odd > trumpnum){
        cout << "IMPOSSIBLE" << nl;
        return;
    }
    sort(all(trumpstring));
    vector<string> match;

    for(auto&a: howmany){
        sort(all(a.second));
        if(a.second.size()%2 == 1){
            match.push_back(a.second[a.second.size()-1]);
            a.second.pop_back();
        }
        if(a.second.size() >= 2){
            for(int i = 0; i < a.second.size(); i+=2){
                cout << a.second[i] << " " << a.second[i+1] << nl;
            }
        }
    }
    sort(all(match));
    for(int i = 0; i < match.size(); i++){
        cout << match[i] << " " << trumpstring[i] << nl;
    }
    for(int j = match.size(); j < trumpstring.size(); j+=2){
        cout << trumpstring[j] << " " << trumpstring[j+1] << nl;  
    }

}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) test_case();
}
