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

void test_case() {
    vector<pair<int, int>> vi(3);
    vector<int> perm = {0, 1, 2};
    double area;
    for(int i = 0; i < 3; i++){
        int x, y; cin >> x >> y;
        area+=x*y;
        vi[i] = {x, y};
    }
    int width = 0;
    if(sqrt(area)*sqrt(area) != area) {
        cout << -1 << nl;   
        return;    
    }
    else width = (int)sqrt(area);

    do
    {
        vector<pair<int, int>> cp(3);
        for(int i = 0; i < 3; i++){
            cp[i] = vi[perm[i]];
        }
        for(int mask = 0; mask < (1 << 3); mask++){
            for(int i = 0; i < 3; i++){
                if(mask & (1 << i)) {
                    swap(cp[i].first, cp[i].second);
                }
            }
            vector<string> sq(width, string(width, '*'));
            bool ok = 1;
            for(int cnt = 0; cnt < 3; cnt++){
                for(int i = 0; i < sq.size(); i++){
                    for(int j = 0; j < sq[i].length(); j++){
                        if(sq[i][j] == '*'){
                            if(i+cp[cnt].first <= width && j+cp[cnt].second <= width){
                                for(int ii = i; ii < i+cp[cnt].first; ii++){
                                    for(int jj = j; jj < j+cp[cnt].second; jj++){
                                        if(sq[ii][jj]=='*') {
                                            sq[ii][jj]='A'+perm[cnt];  
                                        } else{
                                            ok = 0;
                                        }
                                    }
                                }
                                goto next;
                            } else{
                                ok = 0;
                            }
                        }
                    }
                }
                next:
                if(ok && cnt==2){
                    debug(perm);
                    cout << width << nl;
                    for(string s: sq){
                        cout << s << nl;
                    }
                    return;
                }
                if(!ok) break;
            }

        }
    } while (next_permutation(perm.begin(), perm.begin()+3));
    
    cout << -1 << nl;
}

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
