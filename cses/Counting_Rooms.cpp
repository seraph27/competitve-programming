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

int n, m; 
vector<string> room;
vector<vector<bool>> vis;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
    vis[x][y] = 1;
    for(int d = 0; d < 4; d++){
        int nx = x+dx[d], ny = y+dy[d];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && room[nx][ny] == '.') dfs(nx, ny);
    }
}

void test_case(){
    cin >> n >> m;
    room.resize(n);
    vis.resize(n, vector<bool>(m, false));
    for(auto&a: room) cin >> a;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && room[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << nl;
}


//bfs

// void test_case() {
//     int n, m; cin >> n >> m;
//     vector<string> room(n);
//     vector<vector<bool>> vis(n, vector<bool>(m, false));
//     for(auto&a: room) cin >> a;

//     int ans = 0;
//     queue<ar<int, 2>> bfs; 

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(!vis[i][j]){
//                 vis[i][j] = true;
//                 if(room[i][j] == '.'){
//                     bfs.push({i, j});
//                     while(!bfs.empty()){     
//                         auto [x, y] = bfs.front();
//                         bfs.pop();
//                         if(x+1 < n && !vis[x+1][y] && room[x+1][y] == '.') bfs.push({x+1, y}), vis[x+1][y] = true;  
//                         if(y+1 < m && !vis[x][y+1] && room[x][y+1] == '.') bfs.push({x, y+1}), vis[x][y+1] = true; 
//                         if(x-1 >= 0 && !vis[x-1][y] && room[x-1][y] == '.') bfs.push({x-1, y}), vis[x-1][y] = true;  
//                         if(y-1 >= 0 && !vis[x][y-1] && room[x][y-1] == '.') bfs.push({x, y-1}), vis[x][y-1] = true;                      
//                     } 
//                     ans++;
//                 }
//             } else{
//                 continue;
//             }
//         }
//     }
//     cout << ans << nl;

// }

int main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("cardgame.in","r",stdin); freopen("cardgame.out","w",stdout);  //ucsao
    int t = 1;
    //cin >> t;
    while (t--) test_case();
}
