#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define ar array
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define db double

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rint(l, r) uniform_int_distribution<int>(l, r)(rng)
template<typename T> bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename S> constexpr T ifloor(const T a, const S b){return a/b-(a%b&&(a^b)<0);}
template<typename T, typename S> constexpr T iceil(const T a, const S b){return ifloor(a+b-1,b);}
template<typename T> T isqrt(const T &x){T y=sqrt(x+2); while(y*y>x) y--; return y;}
template<typename T>
void sort_unique(vector<T> &vec){
    sort(vec.begin(),vec.end());
    vec.resize(unique(vec.begin(),vec.end())-vec.begin());
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {for (auto &x : v) os << x << " "; return os;}

#ifdef MISAKA
struct _debug {
template<typename T, size_t N> static void __print(const T (&a)[N]) { cerr << '{'; for (size_t i = 0; i < N; ++i) { if (i) cerr << ',';__print(a[i]); }cerr << '}'; }
template<typename T> static void __print(const T &x) {
    if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>) cerr << x;
    else { cerr << '{'; int f{}; for (auto i : x) cerr << (f++?",":""), __print(i); cerr << '}'; }
}
template<typename T, typename V>
static void __print(const pair<T, V> &x) { cerr << '(', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
template<typename T, typename... V>
static void _print(const T& t, const V&... v) { __print(t); if constexpr (sizeof...(v)) cerr << ", ", _print(v...); else cerr << "]\n"; }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif

const char nl = '\n';

volatile int dummy = 0;
void simulate_io(const string &s) {
    dummy = dummy + s.size();
}

//level 1 logger
class Logger {
public:
    Logger() {
        flag = true;
        bg_thread = std::thread([this]() {process_log(); });
    }
    ~Logger() {
        flag = false;
        if(bg_thread.joinable()) {
            bg_thread.join();
        }
    }
    void log(const string &message) {
        std::unique_lock<std::mutex> lock(log_mutex);
        log_queue.push(message);
        lock.unlock();
    }
private:
    void process_log() {
        while(flag || !log_queue.empty()) {
            std::unique_lock<std::mutex> lock(log_mutex);
            if (!log_queue.empty()) {
                auto front = log_queue.front();
                log_queue.pop();
                lock.unlock();
                simulate_io(front);
            } else {
                lock.unlock();
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
    }
    std::thread bg_thread;
    std::mutex log_mutex;
    std::atomic<bool> flag;
    queue<string> log_queue;
};


//level 2 logger with condition variable

class Logger2 {
public:
    Logger2() {
        flag = true;
        bg_thread = std::thread([this]() {process_log(); });
    }
    ~Logger2() {
        {
            std::unique_lock<std::mutex> lock(log_mutex);
            flag = false;
        }
        cv.notify_one();
        if(bg_thread.joinable()) {
            bg_thread.join();
        }
    }
    void log(const string &message) {
        bool was_empty = false;
        {
            std::unique_lock<std::mutex> lock(log_mutex);
            was_empty = log_queue.empty();
            log_queue.push(message);
        }
        if (was_empty) {
            cv.notify_one();
        }
    }
private:
    void process_log() {
        while(true) {
            std::unique_lock<std::mutex> lock(log_mutex);
            cv.wait(lock, [this]() { return !log_queue.empty() || !flag; });
            if (!flag && log_queue.empty()) {
                break;
            }
            while(!log_queue.empty()) {
                auto front = log_queue.front();
                log_queue.pop();
                lock.unlock();
                simulate_io(front);
                lock.lock();
            }
        }
    }
    std::thread bg_thread;
    std::mutex log_mutex;
    std::condition_variable cv;
    bool flag = true;
    queue<string> log_queue;
};

template<typename T>
void bench(const string &name, int iter) {
    auto start = std::chrono::high_resolution_clock::now();

    {
        T logger;
        for(int i = 0; i < iter; i++) {
            logger.log("Log message " + to_string(i));
        }

    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << name << " took " << duration << " ms" << endl;
}
void shiina_mashiro() {
    int MX = 1e6;
    bench<Logger>("lvl1", MX);
    bench<Logger2>("lvl2 ", MX);
    return;
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}


