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
  vvi lang(n);
  bool all_zero = true;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k != 0)
      all_zero = false;
    for (int j = 0; j < k; ++j) {
      int l;
      cin >> l;
      lang[i].pb(l - 1);
    }
  }
  vvi users(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < lang[i].size(); ++j) {
      users[lang[i][j]].pb(i);
    }
  }
  if (all_zero) {
    cout << n << endl;
    return;
  }
  int result = -1;
  vector<bool> was(n);
  for (int i = 0; i < n; i++) {
    if (!was[i])
      ++result;
    was[i] = true;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int j = 0; j < lang[cur].size(); ++j) {
        int lng = lang[cur][j];
        for (int l = 0; l < users[lng].size(); ++l) {
          if (!was[users[lng][l]]) {
            was[users[lng][l]] = true;
            q.push(users[lng][l]);
          }

        }
      }
    }

  }

  cout << result << endl;
}




int main() {
#ifndef ONLINE_JUDGE
  Timer timer;
#endif
#ifdef FILE_INPUT
  FILE* fin  = freopen("input.txt",  "r", stdin );
  FILE* fout = freopen("output.txt", "w", stdout);
#endif
  cout.sync_with_stdio(false);
  cin. sync_with_stdio(false);
  solve();
#ifdef FILE_INPUT
  fclose(fin);
  fclose(fout);
#endif
#ifndef ONLINE_JUDGE
  cout << endl << endl;
  timer.out();
  cin.get();
#endif
  return EXIT_SUCCESS;
}

