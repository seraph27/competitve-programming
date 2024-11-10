#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
using namespace std;
template <typename T>
bool ckmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template <typename T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

#ifdef MISAKA
struct _debug
{
    template <typename T>
    static void __print(const T &x)
    {
        if constexpr (is_convertible_v<T, string> || is_fundamental_v<T>)
            cerr << x;
        else
        {
            cerr << '{';
            int f{};
            for (auto i : x)
                cerr << (f++ ? "," : ""), __print(i);
            cerr << '}';
        }
    }
    template <typename T, typename V>
    static void __print(const pair<T, V> &x) { cerr << ',', __print(x.first), cerr << ',', __print(x.second), cerr << ')'; }
    template <typename T, typename... V>
    static void _print(const T &t, const V &...v)
    {
        __print(t);
        if constexpr (sizeof...(v))
            cerr << ",", _print(v...);
        else
            cerr << "]\n";
    }
};
#define debug(x...) cerr << "[" << #x << "] = [", _debug::_print(x)
#else
#define debug(x...)
#endif
/*
    vector<string> vi(6);
    for(int i = 0; i < 6; i++) {
        string s; cin >> vi[i];
    }

    auto get_string = [&](string s) -> double {
        int type = s[0]=='+' ? 1 : -1;
        int integer_part = s[1]-'0';
        double float_part = stod(s.substr(3, 9));

        float_part *= 1e-9;
        float_part += (double)integer_part;
        return float_part;
    };*/
const char nl = '\n';
void solve()
{

    string s1, s2;
    cin >> s1 >> s2;
    double x = stod(s1.substr(1, 11));
    double y = stod(s2.substr(1, 11));


    // cout << fixed << setprecision(20) << x << '\n' << y;
    int nx = stod(s1.substr(14, s1.size() - 14 + 1));
    int ny = stod(s2.substr(14, s2.size() - 14 + 1));

    if(s1[0] == '-') x *= -1;
    if(s2[0] == '-') y *= -1;
    if(s1[13] == '-') nx *= -1;
    if(s2[13] == '-') ny *= -1;

    // cout << fixed << setprecision(20) << y << "\n";

    double f = 1;

    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        double a = stod(s.substr(1, 11));
        if(s[0] == '-') a *= -1;

             int n = stod(s.substr(14, s1.size() - 14 + 1));
             if(s[13] == '-') n *= -1;

         double temp;
        if(i < 2)
        {
   
        double x1 = x * (pow(10.0, nx - n));
        double y1 = y * (pow(10.0, ny - n));
        temp = x1 + (f * y1);
        if(temp >= 10) temp *= 0.1;
        if(temp <= -10) temp *= 10;
        //  cout << x1 << " " << y1 << "\n";
       // cout <<  fixed << setprecision(20) << temp << "\n";
       // cout << abs(a - temp) << "\n";
        } else if(i == 2)
        {
            temp = x * y;
           int tempn = nx + ny;
            temp = temp * (pow(10.0, tempn - n));
           // debug(temp, a);
        } else
        {
             temp = x / y;
            int tempn = nx - ny;
              //    cout <<  fixed << setprecision(20) << temp << "\n";
                  debug(tempn, tempn - n);

            temp = temp * (pow(10.0, tempn - n));
            
           // cout <<  fixed << setprecision(20) << temp << "\n";
           // cout <<  fixed << setprecision(20) << a << "\n";
        }
        auto chk = [&](string s) -> bool {
            return s == "+0.000000000e+0";
        };

        if(s1==s2 && i==1 && !chk(s)) {
            cout << "Incorrect";
        }
        else if ((abs(a - temp) < 1e-9) && (((abs(a - temp)) / (abs(temp))) < 1e-9)){
            cout << "Correct";
        } else {
            cout << "Incorrect";
        }

        cout << "\n";
        f *= -1;
    }
}

signed main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
}