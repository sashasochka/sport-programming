#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
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

int64 n;
vector<vi64> g;
vi64 val;
vi64 par;
vi64 pl, mi;

void dfs_par(int64 v) {
  for (int64 i = 0; i < g[v].size(); ++i) {
    int64 v2 = g[v][i];
    if (par[v2] == -2) {
      par[v2] = v;
      dfs_par(v2);
    }
  }
}

void dfs(int64 v) {
  for (int64 i = 0; i < g[v].size(); ++i) {
    int64 v2 = g[v][i];
    if (par[v2] == v) {
      dfs(v2);
    }
  }
  int64 a = 0, b = 0;
  for (int64 i = 0; i < g[v].size(); ++i) {
    int64 v2 = g[v][i];
    if (par[v2] == v) {
      a = max(a, pl[v2]);
      b = max(b, mi[v2]);
    }
  }
  int64 res = val[v] + a - b;
  if (res > 0)
    b += res;
  else
    a -= res;
  pl[v] = a;
  mi[v] = b;

}

void solve() {
  cin >> n;
  g.resize(n);
  par.resize(n, -2);
  pl.resize(n);
  mi.resize(n);
  val.resize(n);
  for (int64 i = 0; i < n - 1; ++i) {
    int64 v1, v2;
    cin >> v1 >> v2;
    --v1, --v2;
    g[v1].pb(v2);
    g[v2].pb(v1);
  }
  for (int64 i = 0; i < n; ++i)
    cin >> val[i];
  par[0] = -1;
  dfs_par(0);
  dfs(0);
  cout <<  pl[0] + mi[0] << endl;
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

