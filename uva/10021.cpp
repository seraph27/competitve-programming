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
using namespace std;
const char nl = '\n';

int rd[6][4]{
    { 5, 0, 4, 0 },
    { 1, 5, 1, 4 },
    { 4, 2, 5, 2 },
    { 3, 4, 3, 5 },
    { 0, 1, 2, 3 },
    { 2, 3, 0, 1 },
};

void shiina_mashiro() {
    int x, y; cin >> x >> y;
    int a, b, c, d; cin >> a >> b >> c >> d;
    
    cin.ignore();
    string line;
    bool readingV = false, readingH = false;
    
    int ban[11][11][2]{};
    memset(ban, 0, sizeof ban);
    while(getline(cin, line)) {
        if(line.empty()) break;
        if(line == "v") { readingV = true; readingH = false; continue; }
        if(line == "h") { readingV = false; readingH = true; continue; }
        
        stringstream ss(line);
        int n, m;
        if(ss >> n >> m) {
            if(readingV) ban[n-1][m-1][0] = 1;
            else if(readingH) ban[n-1][m-1][1] = 1;
        }
    }
    
    pii dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    map<tuple<int,int,int>, int> dist;
    priority_queue<ar<int, 4>, vector<ar<int, 4>>, greater<ar<int,4>>> pq;
    
    int startOri = 5;
    pq.push({0, a-1, b-1, startOri});
    dist[{a-1, b-1, startOri}] = 0;
    
    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int cd = top[0], cx = top[1], cy = top[2], ori = top[3];
        
        auto state = make_tuple(cx, cy, ori);
        if(dist.count(state) && dist[state] < cd) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = cx + dirs[i].first, ny = cy + dirs[i].second;
            if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            
            bool blocked = false;
            if(i == 0) blocked = ban[cx][cy][0];
            else if(i == 2) blocked = ban[nx][ny][0];
            else if(i == 1) blocked = ban[cx][cy][1];
            else blocked = ban[nx][ny][1];
            if(blocked) continue;
            
            int newOri = rd[ori][i];
            auto newState = make_tuple(nx, ny, newOri);
            
            if(!dist.count(newState) || dist[newState] > cd + 1) {
                dist[newState] = cd + 1;
                pq.push({cd + 1, nx, ny, newOri});
            }
        }
    }
    
    auto target = make_tuple(c-1, d-1, startOri);
    if(!dist.count(target)) cout << "No solution" << nl;
    else cout << dist[target] << nl;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i) cout << nl;
        shiina_mashiro();
    }
}
