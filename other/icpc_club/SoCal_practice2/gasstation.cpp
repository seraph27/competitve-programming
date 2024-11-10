    #include<bits/stdc++.h>
    #define int long long
    #define sz(x) (int)x.size()
    #define all(x) x.begin(), x.end()
    #define pii pair<int, int>
    #define pb push_back
    #define fi first 
    #define se second
    using namespace std;
    template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
    template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

    #ifdef MISAKA
    struct _debug {
    template<typename T> static void __print(const T &x) {
        if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
        else { cerr << '{'; int f{}; for(auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
    }
    template<typename T, typename V>
    static void __print(const pair<T, V> &x) { cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ')';}
    template<typename T, typename... V> 
    static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ",", _print(v...); else cerr << "]\n"; }}; 
    #define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
    #else 
    #define debug(x...)
    #endif
    const char nl = '\n';

    struct Lane {
        queue<pair<int,int>> left,right; //[duration,id] of cars in queue
        bool ar,al; //true if open
        bool br,bl; //true if open
    };

    struct Arrive {
        int f; //duration
        char side; //'L' for left, 'R' for right
        int id; //the car's id
    };

    struct Exit {
        int pump; //0<=pump<p
        char side; //'L' for left, 'R' for right
        char AB; //'A' for A, 'B' for B
        int id; //the car's id
    };

    void solve() {
        int p, n; cin >> p >> n;
        map<int,vector<Arrive>> arrivals;
        map<int,vector<Exit>> exits;

        map<int,int> ans; //ans[id]=t; t gives the time that car with index id leaves

        //initialize lanes
        vector<Lane> v(p);
        for(int i=0; i<p; i++) {
            v[i].ar=1;
            v[i].al=1;
            v[i].br=1;
            v[i].bl=1;
        }

        //read in car arrivals
        for(int i=0; i<n; i++) {
            int t; cin >> t;
            int f; cin >> f;
            char side; cin >> side;
            arrivals[t].push_back({f,side,i});
        }

        //simulate the times
        for(int t=1; t<=2e5; t++) {
            //cout << "\nt: " << t << "\n\n";
            //go through exits first
            for(Exit e: exits[t]) {
                //cout << "Exit: " << e.pump << " " << e.side << " " << e.AB << " " << e.id << "\n";
                if(e.side=='L' && e.AB=='A') {
                    v[e.pump].al=1;
                }
                else if(e.side=='L' && e.AB=='B') {
                    v[e.pump].bl=1;
                }
                else if(e.side=='R' && e.AB=='A') {
                    v[e.pump].ar=1;
                }
                else if(e.side=='R' && e.AB=='B') {
                    v[e.pump].br=1;
                }
                ans[e.id]=t;
            }

            for(int i=0; i<p; i++) {
                if(v[i].ar && v[i].br) {
                    if(!v[i].right.empty()) {
                        v[i].br=0;
                        pair<int,int> top=v[i].right.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'R','B',id});
                        v[i].right.pop();
                    }
                }
                if(v[i].ar) {
                    if(!v[i].right.empty()) {
                        v[i].ar=0;
                        pair<int,int> top=v[i].right.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'R','A',id});
                        v[i].right.pop();
                    }
                }
                //cout << "Left lane pump status (a,b): " << v[i].al << " " << v[i].bl << "\n";
                if(v[i].al && v[i].bl) {
                    if(!v[i].left.empty()) {
                        v[i].bl=0;
                        pair<int,int> top=v[i].left.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'L','B',id});
                        v[i].left.pop();
                    }
                }
                if(v[i].al) {
                    if(!v[i].left.empty()) {
                        v[i].al=0;
                        pair<int,int> top=v[i].left.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'L','A',id});
                        v[i].left.pop();
                    }
                }
                //cout << "Post-fill lane 0 left: \n";
                //cout << v[i].left.front().first << " " << v[i].left.front().second << "\n";
            }

            //go through arrivals next
            for(Arrive a: arrivals[t]) {
                int mn=1e9;
                int chosenLane=-1;
                if(a.side=='L') {
                    bool chosen=0;
                    for(int i=0; i<p; i++) {
                        if(v[i].al==1) {
                            chosenLane=i;
                            chosen=1;
                            break;
                        }
                    }
                    if(!chosen) {
                        for(int i=0; i<p; i++) {
                            if(v[i].left.size()<mn) {
                                mn=v[i].left.size();
                                chosenLane=i;
                            }
                        }
                    }
                    v[chosenLane].left.push({a.f,a.id});
                }
                else if(a.side=='R') {
                    bool chosen=0;
                    for(int i=0; i<p; i++) {
                        if(v[i].ar==1) {
                            chosenLane=i;
                            chosen=1;
                            break;
                        }
                    }
                    if(!chosen) {
                        for(int i=0; i<p; i++) {
                            if(v[i].right.size()<mn) {
                                mn=v[i].right.size();
                                chosenLane=i;
                            }
                        }
                    }
                    v[chosenLane].right.push({a.f,a.id});
                }
                //cout << "Arrival: " << a.f << " " << a.side << " " << a.id << " " << chosenLane << "\n";
                //cout << "Left lane: \n";
                //cout << v[chosenLane].left.front().first << " " << v[chosenLane].left.front().second << "\n";
                //cout << "Right lane: \n";
                //cout << v[chosenLane].right.front().first << " " << v[chosenLane].right.front().second << "\n";
            }

            //occupy the pumps if possible
            for(int i=0; i<p; i++) {
                if(v[i].ar && v[i].br) {
                    if(!v[i].right.empty()) {
                        v[i].br=0;
                        pair<int,int> top=v[i].right.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'R','B',id});
                        v[i].right.pop();
                    }
                }
                if(v[i].ar) {
                    if(!v[i].right.empty()) {
                        v[i].ar=0;
                        pair<int,int> top=v[i].right.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'R','A',id});
                        v[i].right.pop();
                    }
                }
                //cout << "Left lane pump status (a,b): " << v[i].al << " " << v[i].bl << "\n";
                if(v[i].al && v[i].bl) {
                    if(!v[i].left.empty()) {
                        v[i].bl=0;
                        pair<int,int> top=v[i].left.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'L','B',id});
                        v[i].left.pop();
                    }
                }
                if(v[i].al) {
                    if(!v[i].left.empty()) {
                        v[i].al=0;
                        pair<int,int> top=v[i].left.front();
                        int duration=top.first;
                        int id=top.second;
                        exits[t+duration].push_back({i,'L','A',id});
                        v[i].left.pop();
                    }
                }
                //cout << "Post-fill lane 0 left: \n";
                //cout << v[i].left.front().first << " " << v[i].left.front().second << "\n";
            }
        }
        for(int i=0; i<n; i++) {
            cout << ans[i] << "\n";
        }
    }

    signed main() {
        int t = 1;
        while(t--) {
            solve();
        }
    }