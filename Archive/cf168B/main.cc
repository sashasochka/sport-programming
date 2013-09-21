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
#include <vector>

using namespace std;

typedef long long            int64;
typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef pair<int64,int64>    pii64;
typedef unsigned long long   uint64;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<int>          vi;
typedef vector<vi>           vvi;

const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;
int countbit(int n) { return n == 0 ? 0: countbit(n / 2) + n % 2; }
int lowbit  (int n) { return (n ^ (n-1) ) & n; }
int64 gcd(int64 a, int64 b){ return b == 0? a : gcd(b, a % b); }
int64 lcm(int64 a, int64 b){ return a * b / gcd(a, b); }
int64 toInt64(string s) { istringstream sin(s); int64 t;        sin >> t; return t; }
string toStr (int64 t)  { stringstream sin; sin << t; string s; sin >> s; return s; }
template<typename T> T sqr(T n){ return n * n; }
template<typename T> void out(T& v){
   for(int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1? '\n' : ' ');
}

#define all(a)  (a).begin(), (a).end()
#define pb      push_back

class Timer {
 public:
  double start;
  Timer(){ start = static_cast<double>(clock()); }
  void out(){ cout << "TIME: " << (clock() - start) / CLOCKS_PER_SEC << endl; }
};


//#define FILE_INPUT

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> t(n + 2);
  t.front() = string(m + 2, 'W');
  t.back()  = string(m + 2, 'W');
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    t[i] = 'W' + t[i] + 'W';
  }
  for (int y1 = 1; y1 <= n; ++y1)
    for (int x1 = 1; x1 <= m; ++x1)
      if (t[y1][x1] == 'B') {
        vvi tmp(n+2, vi(m+2, 100000));
        queue<pii> q;
        for (int y = y1; t[y][x1] == 'B'; y++) {
          q.push(pii(y, x1));
          tmp[y][x1] = 0;
        }
        for (int y = y1; t[y][x1] == 'B'; y--) {
          q.push(pii(y, x1));
          tmp[y][x1] = 0;
        }

        for (int x = x1; t[y1][x] == 'B'; x++) {
          q.push(pii(y1, x));
          tmp[y1][x] = 0;
        }
        for (int x = x1; t[y1][x] == 'B'; x--) {
          q.push(pii(y1, x));
          tmp[y1][x] = 0;
        }

        while (!q.empty()) {
          pii coord = q.front();
          q.pop();
          int y2 = coord.first, x2 = coord.second;

          for (int y = y2; t[y][x2] == 'B'; y++)
            tmp[y][x2] = min(tmp[y][x2], 1);
          for (int y = y2; t[y][x2] == 'B'; y--)
            tmp[y][x2] = min(tmp[y][x2], 1);
          for (int x = x2; t[y2][x] == 'B'; x++)
            tmp[y2][x] = min(tmp[y2][x], 1);
          for (int x = x1; t[y2][x] == 'B'; x--)
            tmp[y2][x] = min(tmp[y2][x], 1);
        }
        for (int y3 = 1; y3 <= n; y3++)
          for (int x3 = 1; x3 <= m; ++x3)
            if (t[y3][x3] == 'B' && tmp[y3][x3] > 1) {
              cout << "NO" << endl;
              return;
            }

      }
  cout << "YES" << endl;
}




int main() {
#ifndef ONLINE_JUDGE
  Timer timer;
#endif
#ifdef FILE_INPUT
  freopen("input.txt",  "r", stdin );
  freopen("output.txt", "w", stdout);
#endif
  cout.sync_with_stdio(false);
  cin. sync_with_stdio(false);
  solve();
#ifdef FILE_INPUT
  fclose(stdin);
  fclose(stdout);
#endif
#ifndef ONLINE_JUDGE
  cout << endl << endl;
  timer.out();
  cin.get();
#endif
  return EXIT_SUCCESS;
}

