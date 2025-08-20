// Problem: XOR Game
// Contest: START199B
// URL: https://www.codechef.com/START199B/problems/XORGAME1
// Time Limit: 3000
// Start: Wed Aug 13 11:39:39 2025
// mintemplate
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

struct Trie {
	Trie *children[2] = {};
	int cnt = 0;  // # of numbers with this bit
};

void add(Trie *root, int x) {
	Trie *cur = root;
	for (int i = 30; i >= 0; i--) {
		bool has_bit = x & (1 << i);
		if (cur->children[has_bit] == NULL) {
			// add bit node to trie if there isn't already
			cur->children[has_bit] = new Trie;
		}
		cur->children[has_bit]->cnt++;
		cur = cur->children[has_bit];
	}
}

void remove(Trie *root, int x) {
	Trie *cur = root;
	for (int i = 30; i >= 0; i--) {
		bool has_bit = x & (1 << i);
		cur->children[has_bit]->cnt--;
		cur = cur->children[has_bit];
	}
}

int query(Trie *root, int x) {
	Trie *cur = root;
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		bool has_bit = x & (1 << i);
		if (cur->children[has_bit] != NULL && cur->children[has_bit]->cnt > 0) {
			// we go down the same bit
			cur = cur->children[has_bit];
		} else {
			/*
			 * we go down a different bit,
			 * xor increases by 2^i
			 */
			cur = cur->children[!has_bit];
			res += 1 << i;
		}
	}
	return res;
}

void shiina_mashiro() {
    int n; cin >> n;
    vector<int> vi(n);
    int ans = 0;
    for(auto&a: vi) cin >> a, ans ^= a;

    Trie tr;
    for(auto&a: vi) {
        add(&tr, a);
    }

    int best = 0;
    for(auto &x : vi) { 
        remove(&tr, x);
        int msk = ans ^ x;
        int curr = min(msk, query(&tr, msk));
        ckmax(best, curr);
        add(&tr, x);
    }
    cout << best << nl;

}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) shiina_mashiro();
}

