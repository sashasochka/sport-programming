#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long            int64;
typedef unsigned long long   uint64;
typedef pair<int,  int>      pii;
typedef pair<int64,int64>    pii64;
typedef pair<double, double> pdd;
typedef vector<int>          vi;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<vi>           vvi;
typedef vector<vi>           vvi64;

const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;
int countbit(int n) { return n == 0 ? 0: countbit(n / 2) + n % 2; }
int lowbit  (int n) { return (n ^ (n-1) ) & n; }
int64 gcd(int64 a, int64 b) { return b == 0? a : gcd(b, a % b); }
int64 lcm(int64 a, int64 b) { return a * b / gcd(a, b); }
int64 toInt64(string s) { istringstream sin(s); int64 t;        sin >> t; return t; }
string toStr (int64 t)  { stringstream sin; sin << t; string s; sin >> s; return s; }
template<typename T> T sqr(T n) { return n * n; }
template<typename T> void out(T& v) {
   for(int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1? '\n' : ' ');
}

#define all(a)  ((a).begin(), (a).end())
#define pb      push_back

class Timer {
  public:
    double start;
    Timer() { start = static_cast<double>(clock()); }
    void out() { cout << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl; }
};


//#define FILE_INPUT
int n, m;
int X, Y;
int a, b;
int w,h;

bool is_ok(int x, int y) { // x,y - left down corner
    if (x < 0 || (x + w) > n)
        return false;
    if (y < 0 || y + h > m)
        return false;
    if (x > X || x + w < X)
        return false;
    if (y > Y || y + h < Y)
        return false;
    return true;
}

bool better(int x, int y, int x2, int y2) {
    if(!is_ok(x2, y2)) {
        return true;
    } if (!is_ok(x, y)) {
        return false;
    }
    int d1 = sqr(2 * x + w - 2 * X) + sqr(2 * y + h - 2 * Y);
    int d2 = sqr(2 * x2 + w - 2 * X) + sqr(2 * y2 + h - 2 * Y);
    if (d1 != d2)
        return d1 < d2;
    else
        return (x != x2 ? (x < x2) : y < y2);
}

int x_ = -1, y_ = -1;
int resX = -1, resY = -1;


void solve() {
    cin >> n >> m >>
            X >> Y >>
            a >> b;
    double dw = (double) a / n;
    double dh = (double) b / m;
    if (dw > dh) {
        w = (n / a * a);
        h = w / a * b;
    } else {
        h = m / b * b;
        w = h / b * a;
    }
    int idx = X - (w + 1) / 2;
    int idy = Y - (h + 1) / 2;
    for (int dx = 0; dx <= 1; dx++) {
        for (int dy = 0; dy <=1; dy++) {
            if (better(idx+dx, idy+dy, resX, resY)) {
                resX = idx + dx;
                resY = idy + dy;
            }
        }
    }
    printf("%d %d %d %d", resX, resY, resX + w, resY + h);
}




int main() {
#ifndef ONLINE_JUDGE
    Timer timer;
#endif
#ifdef FILE_INPUT
    FILE* fin  = freopen("input.txt", "r", stdin);
    FILE* fout = freopen("output.txt", "w", stdout);
#endif
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    solve();
#ifdef FILE_INPUT
    fclose(fin);
    fclose(fout);
#endif
#ifndef ONLINE_JUDGE
    cout << endl << endl;
    timer.out();
#endif
    return EXIT_SUCCESS;
}

