// Problem: P1784 数独
// Contest: unknown_contest
// URL: https://www.luogu.com.cn/problem/P1784
// Time Limit: 1000
// Start: Thu Aug 28 09:53:54 2025
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

template<int CAP>
struct DLX {
  int n, m, tot, ans;
  int L[CAP], R[CAP], U[CAP], D[CAP], col[CAP], row[CAP];
  vector<int> firstRow, sizCol, stk;

  void build(int r, int c) {
    n = r; m = c; tot = m; ans = 0;
    for (int i = 0; i <= m; ++i) { L[i] = i - 1; R[i] = i + 1; U[i] = D[i] = i; }
    L[0] = m; R[m] = 0;
    firstRow.assign(n + 1, 0);
    sizCol.assign(m + 1, 0);
    stk.assign(n + 1, 0);
  }

  void insert(int r, int c) {
    ++tot;
    col[tot] = c; row[tot] = r; ++sizCol[c];
    D[tot] = D[c]; U[D[c]] = tot; U[tot] = c; D[c] = tot;
    if (!firstRow[r]) firstRow[r] = L[tot] = R[tot] = tot;
    else { R[tot] = R[firstRow[r]]; L[R[firstRow[r]]] = tot; L[tot] = firstRow[r]; R[firstRow[r]] = tot; }
  }

  void remove(int c) {
    L[R[c]] = L[c]; R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
      for (int j = R[i]; j != i; j = R[j]) { U[D[j]] = U[j]; D[U[j]] = D[j]; --sizCol[col[j]]; }
  }

  void recover(int c) {
    for (int i = U[c]; i != c; i = U[i])
      for (int j = L[i]; j != i; j = L[j]) { ++sizCol[col[j]]; U[D[j]] = j; D[U[j]] = j; }
    L[R[c]] = c; R[L[c]] = c;
  }

  bool dance(int dep = 0) {
    if (R[0] == 0) { ans = dep; return true; }
    int c = R[0];
    for (int j = R[0]; j != 0; j = R[j]) if (sizCol[j] < sizCol[c]) c = j;
    remove(c);
    for (int i = D[c]; i != c; i = D[i]) {
      stk[dep] = row[i];
      for (int j = R[i]; j != i; j = R[j]) remove(col[j]);
      if (dance(dep + 1)) return true;
      for (int j = L[i]; j != i; j = L[j]) recover(col[j]);
    }
    recover(c);
    return false;
  }
};

void shiina_mashiro() {
    vector<vector<int>> g(9, vector<int>(9));
    for(int r = 0; r < 9; r++) for(int c = 0; c < 9; c++) {
        cin >> g[r][c];
    }

    DLX<5000> dl;
    dl.build(729, 324);
    vector<int> rr(730), cc(730), dd(730);
    static constexpr int N = 9;
    static constexpr int S = N * N;
    static constexpr int CELL = 0;
    static constexpr int ROW  = S;
    static constexpr int COL  = 2 * S;
    static constexpr int BOX  = 3 * S;
    
    auto add = [&](int r, int c, int d, int id) {
      int b = (r / 3) * 3 + (c / 3);
      int cellCol = CELL + r * N + c;
      int rowCol  = ROW  + r * N + d;
      int colCol  = COL  + c * N + d;
      int boxCol  = BOX  + b * N + d;
      rr[id] = r; cc[id] = c; dd[id] = d;
      dl.insert(id, cellCol + 1);
      dl.insert(id, rowCol  + 1);
      dl.insert(id, colCol  + 1);
      dl.insert(id, boxCol  + 1);
    };
    int id = 0;
    int rowMask[9] = {}, colMask[9] = {}, boxMask[9] = {};
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (g[r][c]) {
                int d = g[r][c]-1, b = (r/3)*3 + (c/3);
                rowMask[r] |= 1<<d; colMask[c] |= 1<<d; boxMask[b] |= 1<<d;
            }
        }
    }
    for(int r = 0; r < 9; r++) for(int c = 0; c < 9; c++) {
        if (g[r][c]) { int d = g[r][c]-1; add(r,c,d,++id); continue; }
        int b = (r/3)*3 + (c/3);
        int ban = rowMask[r] | colMask[c] | boxMask[b];
        for (int d = 0; d < 9; ++d) if (!(ban & (1<<d))) add(r,c,d,++id);
    }

    dl.dance();
    for(int k = 0; k < dl.ans; k++) {
        int x = dl.stk[k];
        g[rr[x]][cc[x]] = dd[x] + 1;
    }
    for(int r = 0; r < 9; r++) {
        cout << g[r] << nl;
    }
}

signed main() {    
    cin.tie(0)->sync_with_stdio(0);
    //freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    int t = 1;
    //cin >> t;
    while (t--) shiina_mashiro();
}

